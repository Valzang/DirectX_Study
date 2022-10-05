#pragma once


class cObject
{
protected:
	LONG	m_ulRefCount;

public:
	cObject();
	~cObject();

	virtual void AddRef();
	virtual void Release();
};

