#include "pch.h"
#include "CInventory.h"


CInventory::CInventory()
	:m_iCount(0)
{
}
CInventory::~CInventory()
{
}

void CInventory::PushItem(CItem _cItem)
{
	if (m_iCount >= 10)
	{
		cout << "ÀåºñÃ¢ÀÌ ²Ë Âş½À´Ï´Ù." << endl;
		system("pause");
		return;
	}

	m_cItem[m_iCount++] = _cItem;
}

CItem CInventory::GetItem(int _iIndex)
{
	return m_cItem[_iIndex];
}

void CInventory::PrintItemInfo()
{
	for (int i = 0; i < m_iCount; ++i)
	{
		m_cItem[i].PrintInfo();
	}
}

