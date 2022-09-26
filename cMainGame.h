#pragma once
#include "framework.h"
#include "cCubePC.h"
#include "cGrid.h"

class cCubePC;
class cGrid;

class cMainGame
{
private:
	vector<ST_PC_VERTEX>	m_vecLineVertex;
	vector<ST_PC_VERTEX>	m_vecTriangleVertex;
	cCubePC*				m_pCubePC;		// 6��ü �׸���
	cGrid*					m_pGrid;		// ���� �׸���


public:
	cMainGame();
	~cMainGame();

	void SetUp();
	void Update();
	void Render();

	void SetUp_Line();
	void SetUp_Triangle();
	void Draw_Line();
	void Draw_Triangle();

};

