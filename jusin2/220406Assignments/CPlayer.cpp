#include "pch.h"
#include "CPlayer.h"


CPlayer::CPlayer(CLASS _eClass)
	:m_eClass(CLASS::NONE)
{

	m_sStatInfo = new StatInfo();
	m_sStatInfo->m_iLev = 1;
	m_sStatInfo->m_iExp = 0;

	m_eClass = _eClass;

	switch (_eClass)
	{
	case CLASS::WOR:
	{
		m_cClassName = "전사";

		m_sStatInfo->m_iMaxHp = 100;
		m_sStatInfo->m_iHp = 100;
		m_sStatInfo->m_iAt = 1;
		m_sStatInfo->m_iDt = 2;
	}
	break;
	case CLASS::MAG:
	{
		m_cClassName = "법사";

		m_sStatInfo->m_iMaxHp = 50;
		m_sStatInfo->m_iHp = 50;
		m_sStatInfo->m_iAt = 3;
		m_sStatInfo->m_iDt = 1;
	}
	break;
	case CLASS::ARCH:
	{
		m_cClassName = "궁수";

		m_sStatInfo->m_iMaxHp = 70;
		m_sStatInfo->m_iHp = 70;
		m_sStatInfo->m_iAt = 2;
		m_sStatInfo->m_iDt = 1;
	}
	break;
	}

}
CPlayer::~CPlayer()
{
	if (m_sStatInfo != nullptr)
		delete m_sStatInfo;
}


void CPlayer::PrintInfo()
{
	cout << "직업: " << m_cClassName << "   레벨: " << m_sStatInfo->m_iLev << "   공격력: " << m_sStatInfo->m_iAt << "   방어력: " << m_sStatInfo->m_iDt
		<< "   체력: " << m_sStatInfo->m_iHp << "/" << m_sStatInfo->m_iMaxHp
		<< "   경험치: " << m_sStatInfo->m_iExp << "/" << m_sStatInfo->m_iExp * m_sStatInfo->m_iLev;
}

void CPlayer::GetItemToInven(CItem _cItem)
{
	m_cIven.PushItem(_cItem);
}

void CPlayer::PrintInvenInfos()
{
	m_cIven.PrintItemInfo();
	system("pause");
}

bool CPlayer::Attacked(int _iDamage)
{
	m_sStatInfo->m_iHp -= _iDamage;

	if (m_sStatInfo->m_iHp <= 0) {
		m_sStatInfo->m_iHp = m_sStatInfo->m_iMaxHp;
		return true;
	}

	return false;
}

int CPlayer::Get_At()
{
	return m_sStatInfo->m_iAt;
}


