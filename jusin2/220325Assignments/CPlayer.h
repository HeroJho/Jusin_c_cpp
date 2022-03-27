#pragma once

#include "CInventory.h"

class CPlayer
{
private:
	StatInfo* m_sStatInfo;
	CLASS m_eClass;
	string m_cClassName;
	CInventory m_cIven;

public:
	void PrintInfo();
	void GetItemToInven(CItem _cItem);
	void PrintInvenInfos();

public:
	bool Attacked(int _iDamage);
	int Get_At();

public:
	CPlayer(CLASS _eClass);
	~CPlayer();

};

