#pragma once

#include "CObject.h"

class CPlayer : public CObject
{
private:
	string m_sName;
	int m_iExp;

public:
	void PrintInfo();
	void GetExp(int _iValue);

public:
	CPlayer(int _iInput);
	~CPlayer();
};

