#include "framework.h"
#include "cObjMap.h"
#include "cObjLoader.h"

cObjMap::cObjMap(IN char* szFolder, IN char* szFile, IN D3DXMATRIXA16* pmat)
{
	Load(szFolder, szFile, pmat);
}

cObjMap::~cObjMap()
{
	m_vecSurface.clear();
}

void cObjMap::Load(IN char* szFolder, IN char* szFile, IN D3DXMATRIXA16* pmat)
{
	cObjLoader loader;
	loader.LoadSurface(m_vecSurface, szFolder, szFile, pmat);	
}

bool cObjMap::GetHeight(IN float x, OUT float& y, IN float z)
{
	D3DXVECTOR3 vRayPos(x, 1000, z);
	D3DXVECTOR3 vRayDir(0, -1, 0);

	for (UINT i = 0; i < m_vecSurface.size(); i+=3)
	{
		float u, v, f;
		// �� ���� ���� ��
		if (D3DXIntersectTri(&m_vecSurface[i + 0],
			&m_vecSurface[i + 1],
			&m_vecSurface[i + 2],
			&vRayPos, &vRayDir, &u, &v, &f))
		{			
			y = 1000 - f;
			return true;
		}
	}

	return false;
}
