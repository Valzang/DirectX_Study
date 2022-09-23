#pragma once
#include "framework.h"

#define g_pDeviceManager	cDeviceManager::Instance()
#define g_pD3DDevice		cDeviceManager::Instance()->GetDevice()

class cDeviceManager
{
	SINGLETON(cDeviceManager)

private:
	LPDIRECT3D9			m_pD3D;// DirectX ����
	LPDIRECT3DDEVICE9	m_pD3DDevice;	// DirectX�� ��ġ ����

public:
	LPDIRECT3DDEVICE9 GetDevice();
	void Destroy();
};

