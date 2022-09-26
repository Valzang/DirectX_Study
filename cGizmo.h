#pragma once
#include "framework.h"

class cGizmo
{
private:
	vector<ST_PC_VERTEX>	m_vecVertex;
	D3DXMATRIXA16			m_matR;

public:
	cGizmo();
	~cGizmo();

	void SetUp(D3DCOLOR color, D3DXMATRIXA16& mat);
	void Render();
};

