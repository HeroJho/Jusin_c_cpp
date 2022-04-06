#pragma once

# include "CObject.h"

class CMonster
	: public CObject
{
private:

public:
	void PrintInfo();

public:
	bool Attacked(int _iDamage);
	int Get_At();

public:
	CMonster(int _sValue);
	~CMonster();

};

