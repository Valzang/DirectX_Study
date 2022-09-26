#include "cGizmo.h"

cGizmo::cGizmo()
{
	D3DXMatrixIdentity(&m_matR);
}

cGizmo::~cGizmo()
{
}

void cGizmo::SetUp(D3DCOLOR color, D3DXMATRIXA16& mat)
{
	m_matR = mat;
	ST_PC_VERTEX v;

	// front ===========================================================================
	v.color = color;
	v.pos = D3DXVECTOR3( 0.0f,  0.0f,  0.0f);	m_vecVertex.push_back(v);
	v.pos = D3DXVECTOR3( 1.0f, -1.0f, -1.0f);	m_vecVertex.push_back(v);
	v.pos = D3DXVECTOR3(-1.0f, -1.0f, -1.0f);	m_vecVertex.push_back(v);

	// right ===========================================================================
	v.pos = D3DXVECTOR3( 0.0f,  0.0f,  0.0f);	m_vecVertex.push_back(v);
	v.pos = D3DXVECTOR3( 1.0f, -1.0f,  1.0f);	m_vecVertex.push_back(v);
	v.pos = D3DXVECTOR3( 1.0f, -1.0f, -1.0f);	m_vecVertex.push_back(v);

	// back ===========================================================================
	v.pos = D3DXVECTOR3( 0.0f,  0.0f, 0.0f);	m_vecVertex.push_back(v);
	v.pos = D3DXVECTOR3(-1.0f, -1.0f, 1.0f);	m_vecVertex.push_back(v);
	v.pos = D3DXVECTOR3( 1.0f, -1.0f, 1.0f);	m_vecVertex.push_back(v);

	// left ===========================================================================
	v.pos = D3DXVECTOR3( 0.0f,  0.0f,  0.0f);	m_vecVertex.push_back(v);
	v.pos = D3DXVECTOR3(-1.0f, -1.0f, -1.0f);	m_vecVertex.push_back(v);
	v.pos = D3DXVECTOR3(-1.0f, -1.0f,  1.0f);	m_vecVertex.push_back(v);

	// bottom ===========================================================================
	v.pos = D3DXVECTOR3(-1.0f, -1.0f, -1.0f);	m_vecVertex.push_back(v);
	v.pos = D3DXVECTOR3( 1.0f, -1.0f, -1.0f);	m_vecVertex.push_back(v);
	v.pos = D3DXVECTOR3( 1.0f, -1.0f,  1.0f);	m_vecVertex.push_back(v);

	// top ===========================================================================
	v.pos = D3DXVECTOR3(-1.0f, -1.0f, -1.0f);	m_vecVertex.push_back(v);
	v.pos = D3DXVECTOR3( 1.0f, -1.0f,  1.0f);	m_vecVertex.push_back(v);
	v.pos = D3DXVECTOR3(-1.0f, -1.0f,  1.0f);	m_vecVertex.push_back(v);
}

void cGizmo::Render()
{
	D3DXMATRIXA16 matWorld, matS;
	D3DXMatrixScaling(&matS, 0.1f, 2.0f, 0.1f);
	D3DXMatrixIdentity(&matWorld);
	matWorld = matS * m_matR;

	g_pD3DDevice->SetRenderState(D3DRS_CULLMODE, FALSE);
	g_pD3DDevice->SetTransform(D3DTS_WORLD, &matWorld);
	g_pD3DDevice->SetFVF(ST_PC_VERTEX::FVF);
	g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLELIST, m_vecVertex.size() / 3, &m_vecVertex[0], sizeof(ST_PC_VERTEX));
}
