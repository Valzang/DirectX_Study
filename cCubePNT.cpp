#include "cCubePNT.h"

cCubePNT::cCubePNT()
{
}

cCubePNT::~cCubePNT()
{
}

void cCubePNT::SetUp()
{
	vector<ST_PNT_VERTEX> vecVertex;
	vecVertex.resize(8);

	vecVertex[0].pos.x = -0.5f;	vecVertex[0].pos.y = -0.5f;	vecVertex[0].pos.z = -0.5f;
	vecVertex[1].pos.x = -0.5f;	vecVertex[1].pos.y =  0.5f;	vecVertex[1].pos.z = -0.5f;
	vecVertex[2].pos.x =  0.5f;	vecVertex[2].pos.y =  0.5f;	vecVertex[2].pos.z = -0.5f;
	vecVertex[3].pos.x =  0.5f;	vecVertex[3].pos.y = -0.5f;	vecVertex[3].pos.z = -0.5f;

	vecVertex[4].pos.x = -0.5f;	vecVertex[4].pos.y = -0.5f;	vecVertex[4].pos.z =  0.5f;
	vecVertex[5].pos.x = -0.5f;	vecVertex[5].pos.y =  0.5f;	vecVertex[5].pos.z =  0.5f;
	vecVertex[6].pos.x =  0.5f;	vecVertex[6].pos.y =  0.5f;	vecVertex[6].pos.z =  0.5f;
	vecVertex[7].pos.x =  0.5f;	vecVertex[7].pos.y = -0.5f;	vecVertex[7].pos.z =  0.5f;

	vector<DWORD> vecIndex;
	// front
	vecIndex.push_back(0); vecIndex.push_back(1); vecIndex.push_back(2);
	vecIndex.push_back(0); vecIndex.push_back(2); vecIndex.push_back(3);
	// back
	vecIndex.push_back(4); vecIndex.push_back(6); vecIndex.push_back(5);
	vecIndex.push_back(4); vecIndex.push_back(7); vecIndex.push_back(6);
	// left
	vecIndex.push_back(4); vecIndex.push_back(5); vecIndex.push_back(1);
	vecIndex.push_back(4); vecIndex.push_back(1); vecIndex.push_back(0);
	// right
	vecIndex.push_back(3); vecIndex.push_back(2); vecIndex.push_back(6);
	vecIndex.push_back(3); vecIndex.push_back(6); vecIndex.push_back(7);
	// top
	vecIndex.push_back(1); vecIndex.push_back(5); vecIndex.push_back(6);
	vecIndex.push_back(2); vecIndex.push_back(6); vecIndex.push_back(2);
	// bottom
	vecIndex.push_back(4); vecIndex.push_back(0); vecIndex.push_back(3);
	vecIndex.push_back(4); vecIndex.push_back(3); vecIndex.push_back(7);

	m_vecVertex.resize(36);

	for (UINT i = 0; i < vecIndex.size(); i += 3)
	{
		m_vecVertex[i+0] = vecVertex[vecIndex[i+0]];
		m_vecVertex[i+1] = vecVertex[vecIndex[i+1]];
		m_vecVertex[i+2] = vecVertex[vecIndex[i+2]];
	}

	D3DXVECTOR3 u, v, n;
	for (int i = 0; i < 36; i += 3)
	{
		u = m_vecVertex[i + 1].pos - m_vecVertex[i].pos;
		v = m_vecVertex[i + 2].pos - m_vecVertex[i].pos;

		// n (노멀벡터)는 u와 v의 외적으로 만들어줌
		D3DXVec3Cross(&n, &u, &v);
		// 단위벡터로 만들어줌
		D3DXVec3Normalize(&n, &n);

		m_vecVertex[i + 0].normal = n;
		m_vecVertex[i + 1].normal = n;
		m_vecVertex[i + 2].normal = n;
	}
}

void cCubePNT::Update()
{
}

void cCubePNT::Render()
{	
	g_pD3DDevice->SetFVF(ST_PNT_VERTEX::FVF);
	g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLELIST, m_vecVertex.size() / 3, &m_vecVertex[0], sizeof(ST_PNT_VERTEX));
}
