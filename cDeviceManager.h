#pragma once
#include "framework.h"

#define g_pDeviceManager	cDeviceManager::Instance()
#define g_pD3DDevice		cDeviceManager::Instance()->GetDevice()

class cDeviceManager
{
	SINGLETON(cDeviceManager)

private:
	LPDIRECT3D9			m_pD3D;// DirectX 관련
	LPDIRECT3DDEVICE9	m_pD3DDevice;	// DirectX의 장치 관련

public:
	LPDIRECT3DDEVICE9 GetDevice();
	void Destroy();
};

