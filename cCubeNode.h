#pragma once
#include "cCubePNT.h"

class cCubeNode : public cCubePNT
{
protected:
	D3DXVECTOR3			m_vLocalPos;
	D3DXMATRIXA16		m_matLocalTM;
	D3DXMATRIXA16		m_matWorldTM;
	vector<cCubeNode*>	m_vecChild;
public :
	cCubeNode();
	virtual ~cCubeNode();

	Synthesize(D3DXMATRIXA16*, m_pParentWorldTM, ParentWorldTM);
	Synthesize(float, m_fRotDeltaX, RotDeltaX);

	virtual void AddChild(cCubeNode* pChild);
	virtual void Destroy();
	virtual void SetUp() override;
	virtual void Update() override;
	virtual void Render() override;

};

