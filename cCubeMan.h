#pragma once
#include "cCharacter.h"
#include "cCubeNode.h"

class cCubeMan : public cCharacter
{
protected:
	cCubeNode*		m_pRoot;
	D3DMATERIAL9	m_stMtl;
	
public :
	cCubeMan();
	virtual ~cCubeMan();

	virtual void SetUp() override;
	virtual void Update() override;
	virtual void Render() override;
};

