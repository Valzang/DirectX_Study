#pragma once
#define g_pObjectManager	cObjectManager::Instance()

class cObject;

class cObjectManager
{
	SINGLETON(cObjectManager);

private:
	set<cObject*> m_setObject;

public:
	void AddObject(cObject* pObject) { m_setObject.insert(pObject); }
	void RemoveObject(cObject* pObject) { m_setObject.erase(pObject); }
	void Destroy()
	{
		m_setObject.clear();
		assert(m_setObject.empty());
	}

};

