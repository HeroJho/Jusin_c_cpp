#include "CObject.h"

CObject::CObject()
{
}

CObject::~CObject()
{
}

void CObject::PrintInfo()
{
	cout << "레벨: " << m_iLev << " 공격력: " << m_iAt << " 체력: " << m_iHp << "/" << m_iMaxHp << endl;
}

bool CObject::Attacked(const CObject* _cObj)
{
	m_iHp -= _cObj->m_iAt;
	if (m_iHp <= 0)
	{
		m_iHp = m_iMaxHp;
		return true;
	}

	return false;
}
