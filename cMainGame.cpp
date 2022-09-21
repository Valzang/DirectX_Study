#include "cMainGame.h"

cMainGame::cMainGame()
	: m_pD3D(NULL)
	, m_pD3DDevice(NULL)
{
}

cMainGame::~cMainGame()
{
	Safe_Release(m_pD3D);
	Safe_Release(m_pD3DDevice);
}

void cMainGame::SetUp()
{
	m_pD3D = Direct3DCreate9(D3D_SDK_VERSION);

	D3DCAPS9	stCaps;
	int			nVertexProcessing;
	m_pD3D->GetDeviceCaps(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, &stCaps);

	// 하드웨어가 지원해준다면 GPU를 사용하고, 지원 못해준다면 CPU를 사용하겠다.
	if (stCaps.DevCaps & D3DDEVCAPS_HWTRANSFORMANDLIGHT)
		nVertexProcessing = D3DCREATE_HARDWARE_VERTEXPROCESSING;
	else
		nVertexProcessing = D3DCREATE_SOFTWARE_VERTEXPROCESSING;

	D3DPRESENT_PARAMETERS stD3DPP;
	ZeroMemory(&stD3DPP, sizeof(D3DPRESENT_PARAMETERS));
	stD3DPP.SwapEffect = D3DSWAPEFFECT_DISCARD;
	stD3DPP.Windowed = true;
	stD3DPP.BackBufferFormat = D3DFMT_UNKNOWN;
	stD3DPP.EnableAutoDepthStencil = true;
	stD3DPP.AutoDepthStencilFormat = D3DFMT_D16;

	m_pD3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL,
						 g_hWnd, nVertexProcessing, &stD3DPP, &m_pD3DDevice);
}

void cMainGame::Update()
{
}

void cMainGame::Render()
{
	// 화면 지우기
	m_pD3DDevice->Clear(NULL, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, 
						D3DCOLOR_XRGB(100,100,205), 1.0f, 0);

	// 새로 그리기
	m_pD3DDevice->BeginScene();

	// 그리기 끝
	m_pD3DDevice->EndScene();


	// 그린 거 넘겨주기
	m_pD3DDevice->Present(NULL, NULL, NULL, NULL);
}
