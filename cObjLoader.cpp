#include "cObjLoader.h"
#include "cGroup.h"
#include "cMtlTex.h"


cObjLoader::cObjLoader()
{
}

cObjLoader::~cObjLoader()
{
}

void cObjLoader::Load(OUT vector<cGroup*>& vecGroup, IN char* szFolder, IN char* szFile)
{
	vector<D3DXVECTOR3> vecV;

	// 텍스쳐
	vector<D3DXVECTOR2> vecVT;

	// 노멀
	vector<D3DXVECTOR3> vecVN;
	vector<ST_PNT_VERTEX> vecVertex;

	string sFullPath(szFolder);
	sFullPath += (string("/") + string(szFile));

	// C 스타일로 파일 열기
	FILE* fp;
	fopen_s(&fp, sFullPath.c_str(), "r");

	string sMtlName;

	while (1)
	{
		if (feof(fp))
			break;
		char szTemp[1024];
		fgets(szTemp, 1024, fp);
		
		if (szTemp[0] == '#')
			continue;
		else
		{
			switch (szTemp[0])
			{
				case 'm':
				{
					char szMtlFile[1024];
					// %*s : 읽자마자 버린다는 뜻.
					// %*s %s : 하나는 버리고 하나는 읽어서 저장
					sscanf_s(szTemp, "%*s %s", szMtlFile, 1024);
					LoadMtlLib(szFolder, szMtlFile);
				}
					break;
				case 'g':
					if (!vecVertex.empty())
					{
						cGroup* pGroup = new cGroup;
						pGroup->SetVertex(vecVertex);
						pGroup->SetMtlTex(m_mapMtlTex[sMtlName]);
						vecGroup.push_back(pGroup);
						vecVertex.clear();
					}
					break;
				case 'v':
					switch (szTemp[1])
					{
						case ' ':
						{
							float x, y, z;
							sscanf_s(szTemp, "%*s %f %f %f", &x, &y, &z);
							vecV.push_back(D3DXVECTOR3(x, y, z));
						}
							break;
						case 't':
						{
							float u, v;
							sscanf_s(szTemp, "%*s %f %f %*f", &u, &v);
							vecVT.push_back(D3DXVECTOR2(u, v));
						}
							break;
						case 'n':
						{
							float x, y, z;
							sscanf_s(szTemp, "%*s %f %f %f", &x, &y, &z);
							vecVN.push_back(D3DXVECTOR3(x, y, z));
						}
							break;
					}
					break;
				case 'u':
				{
					char szMtlName[1024];
					sscanf_s(szTemp, "%*s %s", szMtlName, 1024);
					sMtlName = string(szMtlName);
				}
					break;
				case 'f':
				{
					int nIndex[3][3];
					sscanf_s(szTemp, "%*s %d/%d/%d %d/%d/%d %d/%d/%d",
							 &nIndex[0][0], &nIndex[0][1], &nIndex[0][2],
							 &nIndex[1][0], &nIndex[1][1], &nIndex[1][2],
							 &nIndex[2][0], &nIndex[2][1], &nIndex[2][2]);

					for (int i = 0; i < 3; ++i)
					{
						ST_PNT_VERTEX v;
						v.pos = vecV[nIndex[i][0] - 1];
						v.texture = vecVT[nIndex[i][1] - 1];
						v.normal = vecVN[nIndex[i][2] - 1];
						vecVertex.push_back(v);
					}
				}
					break;
			}
		}
	}

	fclose(fp);

	for (auto it : m_mapMtlTex)
	{
		Safe_Release(it.second);
	}
	m_mapMtlTex.clear();
	
}

void cObjLoader::LoadMtlLib(char* szFolder, char* szFile)
{
	string sFullPath(szFolder);
	sFullPath += (string("/") + string(szFile));

	// C 스타일로 파일 열기
	FILE* fp;
	fopen_s(&fp, sFullPath.c_str(), "r");

	string sMtlName;

	while (1)
	{
		if (feof(fp))
			break;

		char szTemp[1024];
		fgets(szTemp, 1024, fp);

		if (szTemp[0] == '#')
			continue;
		else
		{
			switch (szTemp[0])
			{
				case 'n':
					char szMtlName[1024];
					sscanf_s(szTemp, "%*s %s", szMtlName, 1024);
					sMtlName = string(szMtlName);
					if (m_mapMtlTex.find(sMtlName) == m_mapMtlTex.end())
						m_mapMtlTex[sMtlName] = new cMtlTex;
					break;
				case 'K':
					if (szTemp[1] == 'a')
					{
						float r, g, b;
						sscanf_s(szTemp, "%*s %f %f %f", &r, &g, &b);
						m_mapMtlTex[sMtlName]->GetMaterial().Ambient.r = r;
						m_mapMtlTex[sMtlName]->GetMaterial().Ambient.g = g;
						m_mapMtlTex[sMtlName]->GetMaterial().Ambient.b = b;
						m_mapMtlTex[sMtlName]->GetMaterial().Ambient.a = 1.0f;
					}
					else if (szTemp[1] == 'd')
					{
						float r, g, b;
						sscanf_s(szTemp, "%*s %f %f %f", &r, &g, &b);
						m_mapMtlTex[sMtlName]->GetMaterial().Diffuse.r = r;
						m_mapMtlTex[sMtlName]->GetMaterial().Diffuse.g = g;
						m_mapMtlTex[sMtlName]->GetMaterial().Diffuse.b = b;
						m_mapMtlTex[sMtlName]->GetMaterial().Diffuse.a = 1.0f;
					}
					else if (szTemp[1] == 's')
					{
						float r, g, b;
						sscanf_s(szTemp, "%*s %f %f %f", &r, &g, &b);
						m_mapMtlTex[sMtlName]->GetMaterial().Specular.r = r;
						m_mapMtlTex[sMtlName]->GetMaterial().Specular.g = g;
						m_mapMtlTex[sMtlName]->GetMaterial().Specular.b = b;
						m_mapMtlTex[sMtlName]->GetMaterial().Specular.a = 1.0f;
					}
					break;
				case 'd':
					float d;
					sscanf_s(szTemp, "%*s %f", &d);
					m_mapMtlTex[sMtlName]->GetMaterial().Power = d;
					break;
				case 'm':
					char szTexFile[1024];
					sscanf_s(szTemp, "%*s %s", szTexFile, 1024);
					sFullPath = string(szFolder);
					sFullPath += (string("/") + string(szTexFile));

					LPDIRECT3DTEXTURE9 pTexture =
						g_pTextureManager->GetTexture(sFullPath);
					m_mapMtlTex[sMtlName]->SetTexture(pTexture);

					break;
			}
		}

	}
}
