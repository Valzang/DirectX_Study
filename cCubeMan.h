#pragma once
#include "cCharacter.h"
#include "cCubeNode.h"

class cCubeMan : public cCharacter
{
protected:
	cCubeNode*		m_pRoot;
	D3DMATERIAL9	m_stMtl;

	LPDIRECT3DTEXTURE9		m_pTexture;
	
public :
	cCubeMan();
	virtual ~cCubeMan();

	virtual void SetUp() override;
	virtual void Update(iMap* pMap) override;
	virtual void Render() override;
};

