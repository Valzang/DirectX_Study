#include "framework.h"

cObject::cObject()
	: m_ulRefCount(1)
{
	g_pObjectManager->AddObject(this);
}

cObject::~cObject()
{
	g_pObjectManager->RemoveObject(this);
}

void cObject::AddRef()
{
	// 여기 떄문에 메모리 릭
	++m_ulRefCount;
}

void cObject::Release()
{
	--m_ulRefCount;
	if (m_ulRefCount <= 0)
		delete this;
}
