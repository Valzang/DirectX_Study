#pragma once


class cObject
{
protected:
	LONG	m_ulRefCount;

public:
	cObject();
	virtual ~cObject();

	virtual void AddRef();
	virtual void Release();
};

