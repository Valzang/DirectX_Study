#pragma once
#include "framework.h"

class cCubePC;
class cGrid;
class cCamera;
class cCubeMan;

class cBody;
class cHead;
//class cLeftArm;
//class cRightArm;
//class cLeftLeg;
//class cRightLeg;
class cGroup;
class cObjLoader;


class cMainGame
{
private:
	vector<ST_PC_VERTEX>	m_vecLineVertex;
	vector<ST_PC_VERTEX>	m_vecTriangleVertex;
	cCubePC*				m_pCubePC;		// 6면체 그리기
	cGrid*					m_pGrid;		// 격자 그리기
	cCamera*				m_pCamera;
	cCubeMan*				m_pCubeMan;
	vector<cGroup*>			m_vecGroup;

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

	void SetUp_Obj();
	void Draw_Obj();

};

