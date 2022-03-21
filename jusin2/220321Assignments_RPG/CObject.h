#pragma once

#include <iostream>
using namespace std;

class CObject
{
protected:
	int m_iHp;
	int m_iMaxHp;
	int m_iAt;
	int m_iLev;

protected:
	void PrintInfo();

public:
	bool Attacked(const CObject* _cObj);

public:
	CObject();
	~CObject();

};

