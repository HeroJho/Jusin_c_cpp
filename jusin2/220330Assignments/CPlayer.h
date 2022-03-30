#pragma once

#include "CObj.h"

class CPlayer final : public CObj
{
private:
	int m_iGold;

public:
	CPlayer(string _cName, int _iAt, int _iDt, int _iMaxHp, int _iGold = 1000);
	~CPlayer();

};

