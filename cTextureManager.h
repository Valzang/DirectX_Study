#pragma once
#define g_pTextureManager	cTextureManager::Instance()

#include "framework.h"

class cTextureManager
{
	SINGLETON(cTextureManager)
private:
	map<string, LPDIRECT3DTEXTURE9>	m_mapTexture;

public:
	LPDIRECT3DTEXTURE9	GetTexture(char* szFullPath);
	LPDIRECT3DTEXTURE9	GetTexture(string& szFullPath);
	void Destroy();
};

