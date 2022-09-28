#include "cCubeMan.h"

#include "cBody.h"
#include "cHead.h"
#include "cLeftArm.h"
#include "cRightArm.h"
#include "cLeftLeg.h"
#include "cRightLeg.h"

cCubeMan::cCubeMan()
	: m_pRoot(NULL)
{
}

cCubeMan::~cCubeMan()
{
	if (m_pRoot)
		m_pRoot->Destroy();	
}

void cCubeMan::SetUp()
{
	cCharacter::SetUp();

	// >> =================================================

	ZeroMemory(&m_stMtl, sizeof(D3DMATERIAL9));
	m_stMtl.Ambient = D3DXCOLOR(0.7F, 0.7F, 0.7F, 1.0f);
	m_stMtl.Diffuse = D3DXCOLOR(0.7F, 0.7F, 0.7F, 1.0f);
	m_stMtl.Specular = D3DXCOLOR(0.7F, 0.7F, 0.7F, 1.0f);


	// << =================================================

	cBody* pBody = new cBody;
	pBody->SetUp();
	pBody->SetParentWorldTM(&m_matWorld);
	
	m_pRoot = pBody;

	cHead* pHead = new cHead;
	pHead->SetUp();
	m_pRoot->AddChild(pHead);

	cLeftArm* pLeftArm = new cLeftArm;
	pLeftArm->SetUp();
	m_pRoot->AddChild(pLeftArm);
	
	cRightArm* pRightArm = new cRightArm;
	pRightArm->SetUp();
	m_pRoot->AddChild(pRightArm);
	
	cLeftLeg* pLeftLeg = new cLeftLeg;
	pLeftLeg->SetUp();
	m_pRoot->AddChild(pLeftLeg);
	
	cRightLeg* pRightLeg = new cRightLeg;
	pRightLeg->SetUp();
	m_pRoot->AddChild(pRightLeg);

}

void cCubeMan::Update()
{
	cCharacter::Update();

	if (m_pRoot)
		m_pRoot->Update();
}

void cCubeMan::Render()
{
	if (g_pD3DDevice)
	{
		g_pD3DDevice->SetRenderState(D3DRS_LIGHTING, true);
		g_pD3DDevice->SetMaterial(&m_stMtl);
		cCharacter::Render();

		D3DXMATRIXA16 matWorld;
		D3DXMatrixIdentity(&matWorld);
		g_pD3DDevice->SetTransform(D3DTS_WORLD, &matWorld);
		if (m_pRoot)
			m_pRoot->Render();
		g_pD3DDevice->SetRenderState(D3DRS_LIGHTING, false);
	}
	
}
