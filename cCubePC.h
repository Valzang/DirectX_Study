#pragma once
#include "framework.h"



class cCubePC
{
private:
	vector<ST_PC_VERTEX>	m_vecVertex;
	float					m_fRotY;
	D3DXVECTOR3				m_vDirection;
	D3DXVECTOR3				m_vPosition;
	D3DXMATRIXA16			m_matWorld;


public:
	cCubePC();
	~cCubePC();

	void			SetUp();
	void			Update();
	void			Render();
	D3DXVECTOR3&	GetPosition();

};

