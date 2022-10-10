#pragma once
#include "framework.h"

class cCharacter
{
protected:
	float			m_fRotY;
	D3DXVECTOR3		m_vDirection;
	D3DXVECTOR3		m_vPosition;
	D3DXMATRIXA16	m_matWorld;
	iMap*			m_pMap;

public:
	cCharacter();
	virtual ~cCharacter();

	virtual void SetUp();
	virtual void Update(iMap* pMap);
	virtual void Render();
	virtual D3DXVECTOR3& GetPosition();
};

