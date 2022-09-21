#pragma once
#include "framework.h"

class cMainGame
{
private:
	LPDIRECT3D9			m_pD3D;// DirectX ����
	LPDIRECT3DDEVICE9	m_pD3DDevice;	// DirectX�� ��ġ ����

public:
	cMainGame();
	~cMainGame();

	void SetUp();
	void Update();
	void Render();

};

