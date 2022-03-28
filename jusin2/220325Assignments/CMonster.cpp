#include "pch.h"
#include "CMonster.h"


CMonster::CMonster(int _sValue)
{
	switch (_sValue)
	{
		case 1:
		{
			m_sStatInfo = new StatInfo();
			m_sStatInfo->m_iLev = 1;
			m_sStatInfo->m_iExp = 5;

			m_sStatInfo->m_iMaxHp = 5;
			m_sStatInfo->m_iHp = 5;
			m_sStatInfo->m_iAt = 1;
			m_sStatInfo->m_iDt = 1;
		}
			break;
		case 2:
		{
			m_sStatInfo = new StatInfo();
			m_sStatInfo->m_iLev = 2;
			m_sStatInfo->m_iExp = 15;

			m_sStatInfo->m_iMaxHp = 10;
			m_sStatInfo->m_iHp = 10;
			m_sStatInfo->m_iAt = 2;
			m_sStatInfo->m_iDt = 2;
		}
			break;
		case 3:
		{
			m_sStatInfo = new StatInfo();
			m_sStatInfo->m_iLev = 3;
			m_sStatInfo->m_iExp = 45;

			m_sStatInfo->m_iMaxHp = 30;
			m_sStatInfo->m_iHp = 30;
			m_sStatInfo->m_iAt = 5;
			m_sStatInfo->m_iDt = 4;
		}
			break;
	}
}
CMonster::~CMonster()
{
	if(m_sStatInfo != nullptr)
		delete m_sStatInfo;
}


void CMonster::PrintInfo()
{
	cout << "   레벨: " << m_sStatInfo->m_iLev << "   공격력: " << m_sStatInfo->m_iAt << "   방어력: " << m_sStatInfo->m_iDt
		<< "   체력: " << m_sStatInfo->m_iHp << "/" << m_sStatInfo->m_iMaxHp;
}


bool CMonster::Attacked(int _iDamage)
{
	m_sStatInfo->m_iHp -= _iDamage;

	if (m_sStatInfo->m_iHp <= 0) {
		m_sStatInfo->m_iHp = m_sStatInfo->m_iMaxHp;
		return true;
	}

	return false;
}

int CMonster::Get_At()
{
	return m_sStatInfo->m_iAt;
}
