#pragma once
#include "framework.h"

class cCubePNT
{
protected:
	vector<ST_PNT_VERTEX>	m_vecVertex;

public:
	cCubePNT();
	virtual ~cCubePNT();

	virtual void SetUp();
	virtual void Update();
	virtual void Render();
};

