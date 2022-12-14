#include "cGrid.h"

cGrid::cGrid()
{
}

cGrid::~cGrid()
{
	for (auto p : m_vecGizmo)
	{
		Safe_Delete(p);
	}
	m_vecGizmo.clear();
}

void cGrid::SetUp(int nNumHalfTile, float fInterval)
{
	float fMax = nNumHalfTile * fInterval;
	float fMin = -nNumHalfTile * fInterval;

	ST_PC_VERTEX v;
	for (int i = 1; i <= nNumHalfTile; ++i)
	{
		if (i % 5 == 0)
			v.color = D3DCOLOR_XRGB(255, 255, 255);
		else
			v.color = D3DCOLOR_XRGB(128, 128, 128);

		v.pos = D3DXVECTOR3(fMin, 0, i * fInterval); m_vecVertex.push_back(v);
		v.pos = D3DXVECTOR3(fMax, 0, i * fInterval); m_vecVertex.push_back(v);
		v.pos = D3DXVECTOR3(fMin, 0, -i * fInterval); m_vecVertex.push_back(v);
		v.pos = D3DXVECTOR3(fMax, 0, -i * fInterval); m_vecVertex.push_back(v);

		v.pos = D3DXVECTOR3(i * fInterval, 0 , fMin); m_vecVertex.push_back(v);
		v.pos = D3DXVECTOR3(i * fInterval, 0, fMax); m_vecVertex.push_back(v);
		v.pos = D3DXVECTOR3(-i * fInterval, 0, fMin); m_vecVertex.push_back(v);
		v.pos = D3DXVECTOR3(-i * fInterval, 0, fMax); m_vecVertex.push_back(v);
	}	

	v.color = D3DCOLOR_XRGB(255, 0, 0);
	v.pos = D3DXVECTOR3(fMin, 0, 0); m_vecVertex.push_back(v);
	v.pos = D3DXVECTOR3(fMax, 0, 0); m_vecVertex.push_back(v);
	
	v.color = D3DCOLOR_XRGB(0, 255, 0);
	v.pos = D3DXVECTOR3(0, fMin, 0); m_vecVertex.push_back(v);
	v.pos = D3DXVECTOR3(0, fMax, 0); m_vecVertex.push_back(v);

	v.color = D3DCOLOR_XRGB(0, 0, 255);
	v.pos = D3DXVECTOR3(0, 0, fMin); m_vecVertex.push_back(v);
	v.pos = D3DXVECTOR3(0, 0, fMax); m_vecVertex.push_back(v);

	// : pyramid =======================================================================
	cGizmo* pGizmo = NULL;
	D3DXMATRIXA16	matR;

	pGizmo = new cGizmo;
	D3DXMatrixRotationZ(&matR, D3DX_PI / 2.0f);
	pGizmo->SetUp(D3DCOLOR_XRGB(255, 0, 0), matR);
	m_vecGizmo.push_back(pGizmo);

	pGizmo = new cGizmo;
	D3DXMatrixRotationZ(&matR, D3DX_PI);
	pGizmo->SetUp(D3DCOLOR_XRGB(0, 255, 0), matR);
	m_vecGizmo.push_back(pGizmo);

	pGizmo = new cGizmo;
	D3DXMatrixRotationX(&matR, -D3DX_PI / 2.0f);
	pGizmo->SetUp(D3DCOLOR_XRGB(0, 0, 255), matR);
	m_vecGizmo.push_back(pGizmo);
}

void cGrid::Render()
{
	g_pD3DDevice->SetRenderState(D3DRS_LIGHTING, false);
	D3DXMATRIXA16 matI;
	D3DXMatrixIdentity(&matI);

	g_pD3DDevice->SetTransform(D3DTS_WORLD, &matI);
	g_pD3DDevice->SetFVF(ST_PC_VERTEX::FVF);
	g_pD3DDevice->DrawPrimitiveUP(D3DPT_LINELIST, m_vecVertex.size() / 2, &m_vecVertex[0], sizeof(ST_PC_VERTEX));

	for (auto p : m_vecGizmo)
		p->Render();
}
