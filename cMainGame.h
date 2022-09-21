#pragma once
#include "framework.h"

class cMainGame
{
private:
	LPDIRECT3D9			m_pD3D;// DirectX 관련
	LPDIRECT3DDEVICE9	m_pD3DDevice;	// DirectX의 장치 관련

public:
	cMainGame();
	~cMainGame();

	void SetUp();
	void Update();
	void Render();

};

