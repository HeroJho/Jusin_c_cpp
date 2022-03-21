#pragma once

#include "CObject.h"

class CMonster : public CObject
{
private:
	string m_sName;

public:
	void PrintInfo();

public:
	CMonster(int _iInput);
	~CMonster();
};

