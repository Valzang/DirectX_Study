#include "cLeftLeg.h"

cLeftLeg::cLeftLeg()
{
}

cLeftLeg::~cLeftLeg()
{
}

void cLeftLeg::SetUp()
{
	cCubeNode::SetUp(); // ¡§¿∞∏È√º ∏∏µÍ

	D3DXMATRIXA16 matS, mat, matT;
	D3DXMatrixScaling(&matS, 0.2f, 0.6f, 0.2f);
	D3DXMatrixTranslation(&matT, -0.1f, -0.3f, 0.0f);

	mat = matS * matT;

	for (UINT i = 0; i < m_vecVertex.size(); ++i)
	{
		D3DXVec3TransformCoord(&m_vecVertex[i].pos, &m_vecVertex[i].pos, &mat);
	}

	m_vLocalPos.y = -0.3f;
}
