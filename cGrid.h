#pragma once
#include "framework.h"
#include "cGizmo.h"

class cGrid
{
private:
	vector<ST_PC_VERTEX>	m_vecVertex;
	vector<cGizmo*>			m_vecGizmo;
public:
	cGrid();
	~cGrid();

	void SetUp(int nNumHalfTile = 15, float fInterval = 1.0f);
	void Render();

};

