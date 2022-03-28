#include "pch.h"
#include "CItem.h"

CItem::CItem()
	:m_iId(0)
{
}
CItem::CItem(int _iId)
	: m_iId(0)
{
	switch (_iId)
	{
	case 1:
		m_iId = _iId;
		m_cName = "°Ë";
		break;
	case 2:
		m_iId = _iId;
		m_cName = "°©¿Ê";
		break;
	}
}

CItem::~CItem()
{
}

void CItem::PrintInfo()
{
	cout << m_cName << endl;
}

