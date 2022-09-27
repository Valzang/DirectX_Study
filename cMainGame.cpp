#include "cMainGame.h"

cMainGame::cMainGame()
	: m_pCubePC(NULL)
	, m_pGrid(NULL)
	, m_pCamera(NULL)
{
}

cMainGame::~cMainGame()
{
	Safe_Delete(m_pGrid);
	Safe_Delete(m_pCubePC);
	Safe_Delete(m_pCamera);	
	g_pDeviceManager->Destroy();		
}

void cMainGame::SetUp()
{
	SetUp_Line();
	SetUp_Triangle();

	m_pCubePC = new cCubePC;
	m_pCubePC->SetUp();

	m_pGrid = new cGrid;
	m_pGrid->SetUp();

	m_pCamera = new cCamera;
	m_pCamera->SetUp(&m_pCubePC->GetPosition());

	// ���� ����
	g_pD3DDevice->SetRenderState(D3DRS_LIGHTING, false);
}

void cMainGame::Update()
{	
	if (m_pCubePC)
		m_pCubePC->Update();
	if (m_pCamera)
		m_pCamera->Update();
	if (m_pCubePC)
		m_pCubePC->Update();
}

void cMainGame::Render()
{
	// ȭ�� �����
	g_pD3DDevice->Clear(NULL, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER,
						D3DCOLOR_XRGB(200,200,205), 1.0f, 0);

	// ���� �׸���
	g_pD3DDevice->BeginScene();

	if (m_pCubePC)
		m_pCubePC->Render();

	if (m_pGrid)
		m_pGrid->Render();
	

	// �� & �ﰢ�� �׸��� ===============================================
	//Draw_Line();
	//Draw_Triangle();
	// ===============================================================
	// �׸��� ��
	g_pD3DDevice->EndScene();


	// �׸� �� �Ѱ��ֱ�
	g_pD3DDevice->Present(NULL, NULL, NULL, NULL);
}

void cMainGame::SetUp_Line()
{
	ST_PC_VERTEX v;
	v.color = D3DCOLOR_XRGB(255, 0, 0);
	v.pos = D3DXVECTOR3(0, 2, 0);	m_vecLineVertex.push_back(v);
	v.pos = D3DXVECTOR3(0, -2, 0);	m_vecLineVertex.push_back(v);
}

void cMainGame::SetUp_Triangle()
{
	ST_PC_VERTEX v;
	v.color = D3DCOLOR_XRGB(255, 0, 0);	v.pos = D3DXVECTOR3(-1, -1, 0); 
	m_vecTriangleVertex.push_back(v);
	v.color = D3DCOLOR_XRGB(0, 255, 0); v.pos = D3DXVECTOR3(-1, 1, 0); 
	m_vecTriangleVertex.push_back(v);
	v.color = D3DCOLOR_XRGB(0, 0, 255); v.pos = D3DXVECTOR3(1, 1, 0); 
	m_vecTriangleVertex.push_back(v);
}

void cMainGame::Draw_Line()
{
	D3DXMATRIXA16		matWorld;
	D3DXMatrixIdentity(&matWorld);

	g_pD3DDevice->SetTransform(D3DTS_WORLD, &matWorld);
	g_pD3DDevice->SetFVF(ST_PC_VERTEX::FVF);
	g_pD3DDevice->DrawPrimitiveUP(D3DPT_LINELIST, m_vecLineVertex.size() / 2,
								  &m_vecLineVertex[0], sizeof(ST_PC_VERTEX));
}

void cMainGame::Draw_Triangle()
{
	D3DXMATRIXA16		matWorld;
	D3DXMatrixIdentity(&matWorld);

	g_pD3DDevice->SetTransform(D3DTS_WORLD, &matWorld);
	g_pD3DDevice->SetFVF(ST_PC_VERTEX::FVF);
	g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLELIST, m_vecTriangleVertex.size() / 3,
								  &m_vecTriangleVertex[0], sizeof(ST_PC_VERTEX));
}

void cMainGame::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	if (m_pCamera)
		m_pCamera->WndProc(hWnd, message, wParam, lParam);
}