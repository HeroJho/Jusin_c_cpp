#include "pch.h"
#include "CMonster.h"


CMonster::CMonster(MONSTER _sValue)
	:m_sStatInfo(nullptr)
{
	switch (_sValue)
	{
		case MONSTER::SLIME:
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
		case MONSTER::MUSHROOM:
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
		case MONSTER::ORK:
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
