#pragma once


class cObject
{
protected:
	ULONG	m_ulRefCount;

public:
	cObject();
	~cObject();

	virtual void AddRef();
	virtual void Release();
};

