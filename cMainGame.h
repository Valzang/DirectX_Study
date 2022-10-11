#pragma once

class cCubePC;
class cGrid;
class cCamera;
class cCubeMan;

class cBody;
class cHead;
class cGroup;
class cObjLoader;

class cFrustum;


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

	iMap*					m_pMap;
	vector<cGroup*>			m_vecMap;

	LPD3DXMESH				m_pSphere;
	vector<ST_SPHERE*>		m_vecCullingSphere;
	D3DMATERIAL9			m_stCullingMtl;
	cFrustum*				m_pFrustum;


public:
	cMainGame();
	~cMainGame();

	void SetUp();
	void Update();
	void Render();

	void SetUp_Line();
	void SetUp_Triangle();
	void Render_Line();
	void Render_Triangle();

	void WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

	void SetUp_Light();
	void SetUp_Texture();
	void Render_Texture();

	void SetUp_Obj();
	void Render_Obj();

	void SetUp_Map();	
	void Render_Map();
	void SetUp_Surface();

	void SetUp_HeightMap();
	void Render_HeightMap();


	void SetUp_Frustum();
	void Render_Frustum();
};

