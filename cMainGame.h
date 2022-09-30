#pragma once
#include "framework.h"
#include "cCubePC.h"
#include "cGrid.h"
#include "cCamera.h"
#include "cCubeNode.h"

#include "cCubeMan.h"
#include "cBody.h"
#include "cHead.h"
#include "cLeftArm.h"
#include "cRightArm.h"
#include "cLeftLeg.h"
#include "cRightLeg.h"

class cMainGame
{
private:
	vector<ST_PC_VERTEX>	m_vecLineVertex;
	vector<ST_PC_VERTEX>	m_vecTriangleVertex;
	cCubePC*				m_pCubePC;		// 6면체 그리기
	cGrid*					m_pGrid;		// 격자 그리기
	cCamera*				m_pCamera;
	cCubeMan*				m_pCubeMan;

	LPDIRECT3DTEXTURE9		m_pTexture;
	vector<ST_PT_VERTEX>	m_vecVertex;


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

	void WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

	void SetUp_Light();
	void SetUp_Texture();
	void Draw_Texture();

};

