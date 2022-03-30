#pragma once

#include "CObj.h"

class CMonster : public CObj
{
private:
	
public:
	void DieSound();

public:
	CMonster(string _cName, int _iAt, int _iDt, int _iMaxHp);
	~CMonster();

};

