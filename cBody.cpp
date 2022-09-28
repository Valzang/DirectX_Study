#include "cBody.h"

cBody::cBody()
{
}

cBody::~cBody()
{
}

void cBody::SetUp()
{
	cCubeNode::SetUp(); // ������ü ����

	D3DXMATRIXA16 matS, mat, matT;
	D3DXMatrixScaling(&matS, 0.4f, 0.6f, 0.2f);
	D3DXMatrixTranslation(&matT, 0.0f, 0.0f, 0.0f);
	
	mat = matS * matT;

	for (UINT i = 0; i < m_vecVertex.size(); ++i)
	{
		D3DXVec3TransformCoord(&m_vecVertex[i].pos, &m_vecVertex[i].pos, &mat);
	}

}
