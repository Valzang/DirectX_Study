#include "cCamera.h"

cCamera::cCamera()
	: m_vCamRotAngle(0, 0, 0)
	, m_vEye(0, 0, -5)
	, m_vLookAt(0, 0, 0)
	, m_vUp(0, 1, 0)
	, m_pvTarget(NULL)
	, m_fCameraDistance(5.0f)
	, m_isLButtonDown(false)
{
	m_ptPrevMouse.x = 0, m_ptPrevMouse.y = 0;
}

cCamera::~cCamera()
{
}

void cCamera::SetUp(D3DXVECTOR3* pvTarget)
{
	m_pvTarget = pvTarget;

	RECT rc;
	GetClientRect(g_hWnd, &rc);

	D3DXMATRIXA16 matProj;
	D3DXMatrixPerspectiveFovLH(&matProj, D3DX_PI / 4.0f,
							   (float)rc.right / (float)rc.bottom,
							   1.0f, 1000.0f);
	g_pD3DDevice->SetTransform(D3DTS_PROJECTION, &matProj);
}

void cCamera::Update()
{
	RECT rc;
	GetClientRect(g_hWnd, &rc);

	D3DXMATRIXA16 matR, matRX, matRY;
	D3DXMatrixRotationX(&matRX, m_vCamRotAngle.x);
	D3DXMatrixRotationY(&matRY, m_vCamRotAngle.y);

	matR = matRX * matRY;

	// 눈의 위치
	m_vEye = D3DXVECTOR3(0, 0, -m_fCameraDistance);

	D3DXVec3TransformCoord(&m_vEye, &m_vEye, &matR);

	// 타겟이 있으면 기존 바라보던 곳에서부터 타겟까지의 거리만큼 눈의 위치를 균일하게 옮겨줌
	if (m_pvTarget)
	{
		m_vLookAt = *m_pvTarget;
		m_vEye += *m_pvTarget;
	}

	// 보는 방향
	D3DXMATRIXA16 matView;
	D3DXMatrixLookAtLH(&matView, &m_vEye, &m_vLookAt, &m_vUp);
	g_pD3DDevice->SetTransform(D3DTS_VIEW, &matView);
}

void cCamera::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
		case WM_LBUTTONDOWN:
			{
				m_ptPrevMouse.x = LOWORD(lParam);
				m_ptPrevMouse.y = HIWORD(lParam);
				m_isLButtonDown = true;
			}
			break;
		case WM_LBUTTONUP:
			m_isLButtonDown = false;
			break;
		case WM_MOUSEMOVE:
			{
				if (m_isLButtonDown)
				{
					POINT ptCurMouse;
					ptCurMouse.x = LOWORD(lParam);
					ptCurMouse.y = HIWORD(lParam);

					// 이전 마우스로부터의 차이값을 통해 이동량을 가져올 것임.
					FLOAT fDeltaX = (float)ptCurMouse.x - m_ptPrevMouse.x;
					FLOAT fDeltaY = (float)ptCurMouse.y - m_ptPrevMouse.y;

					// 여기서 100은 매직 넘버이므로 나중에 바꿀 수 있게끔 하는 것이 좋음.
					m_vCamRotAngle.y += (fDeltaX / 100.0f);
					m_vCamRotAngle.x += (fDeltaY / 100.0f);

					if (m_vCamRotAngle.x < -D3DX_PI / 2.0f + 0.0001f)
						m_vCamRotAngle.x = -D3DX_PI / 2.0f + 0.0001f;
					else if (m_vCamRotAngle.x > D3DX_PI / 2.0f - 0.0001f)
						m_vCamRotAngle.x = D3DX_PI / 2.0f - 0.0001f;

					m_ptPrevMouse = ptCurMouse;
				}
			}
			break;
		case WM_MOUSEWHEEL:
			// 여기서 30은 매직 넘버이므로 나중에 바꿀 수 있게끔 하는 것이 좋음.
			m_fCameraDistance -= (GET_WHEEL_DELTA_WPARAM(wParam) / 30.0f);
			if (m_fCameraDistance < 0.0001f)
				m_fCameraDistance = 0.0001f;
			break;
	}
}
