#include "cMainGame.h"

cMainGame::cMainGame()
	: m_pCubePC(NULL)
	, m_pGrid(NULL)
	, m_pCamera(NULL)
	, m_pCubeMan(NULL)
{
}

cMainGame::~cMainGame()
{
	Safe_Delete(m_pGrid);
	Safe_Delete(m_pCubePC);
	Safe_Delete(m_pCamera);	
	Safe_Delete(m_pCubeMan);
	g_pDeviceManager->Destroy();		
}

void cMainGame::SetUp()
{
	SetUp_Line();
	SetUp_Triangle();

	m_pCubePC = new cCubePC;
	m_pCubePC->SetUp();

	m_pCubeMan = new cCubeMan;
	m_pCubeMan->SetUp();

	m_pGrid = new cGrid;
	m_pGrid->SetUp();

	m_pCamera = new cCamera;
	m_pCamera->SetUp(&m_pCubeMan->GetPosition());

	// 조명 끄기
	SetUp_Light();

	g_pD3DDevice->SetRenderState(D3DRS_LIGHTING, false);
}

void cMainGame::Update()
{	
	if (m_pCubePC)
		m_pCubePC->Update();

	if (m_pCubeMan)
		m_pCubeMan->Update();

	if (m_pCamera)
		m_pCamera->Update();
	
}

void cMainGame::Render()
{
	// 화면 지우기
	g_pD3DDevice->Clear(NULL, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER,
						D3DCOLOR_XRGB(200,200,205), 1.0f, 0);

	// 새로 그리기
	g_pD3DDevice->BeginScene();

	//if (m_pCubePC)
	//	m_pCubePC->Render();

	if (m_pCubeMan)
		m_pCubeMan->Render();

	if (m_pGrid)
		m_pGrid->Render();
	

	// 선 & 삼각형 그리기 ===============================================
	//Draw_Line();
	//Draw_Triangle();
	// ===============================================================
	// 그리기 끝
	g_pD3DDevice->EndScene();


	// 그린 거 넘겨주기
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

void cMainGame::SetUp_Light()
{
	D3DLIGHT9 stLight;
	ZeroMemory(&stLight, sizeof(D3DLIGHT9));
	stLight.Type = D3DLIGHT_DIRECTIONAL;
	stLight.Ambient = D3DXCOLOR(0.8f, 0.8f, 0.8f, 1.0f);
	stLight.Diffuse = D3DXCOLOR(0.8f, 0.8f, 0.8f, 1.0f);
	stLight.Specular = D3DXCOLOR(0.8f, 0.8f, 0.8f, 1.0f);

	D3DXVECTOR3 vDir(1.0f, -1.0f, 1.0f);
	D3DXVec3Normalize(&vDir, &vDir);
	stLight.Direction = vDir;
	g_pD3DDevice->SetLight(0, &stLight);
	g_pD3DDevice->LightEnable(0, true);
}
