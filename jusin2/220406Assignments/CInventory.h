#pragma once
#include "CItem.h"

class CInventory
{
private:
	CItem m_cItem[10];
	int m_iCount;

public:
	void PushItem(CItem _cItem);
	CItem GetItem(int _iIndex);
	void PrintItemInfo();

public:
	CInventory();
	~CInventory();
};

