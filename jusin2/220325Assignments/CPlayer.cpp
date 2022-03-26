#include "pch.h"
#include "CPlayer.h"


CPlayer::CPlayer(CLASS _eClass)
	:m_sStatInfo(nullptr)
	,m_eClass(CLASS::NONE)
{

	m_sStatInfo = new StatInfo();
	m_sStatInfo->m_iLev = 1;
	m_sStatInfo->m_iExp = 0;

	m_eClass = _eClass;

	switch (_eClass)
	{
		case CLASS::WOR:
		{
			m_cClassName = "����";

			m_sStatInfo->m_iMaxHp = 100;
			m_sStatInfo->m_iHp = 100;
			m_sStatInfo->m_iAt = 1;
			m_sStatInfo->m_iDt = 2;
		}
			break;
		case CLASS::MAG:
		{
			m_cClassName = "����";

			m_sStatInfo->m_iMaxHp = 50;
			m_sStatInfo->m_iHp = 50;
			m_sStatInfo->m_iAt = 3;
			m_sStatInfo->m_iDt = 1;
		}
			break;
		case CLASS::ARCH:
		{
			m_cClassName = "�ü�";

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
	if(m_sStatInfo != nullptr)
		delete m_sStatInfo;
}


void CPlayer::PrintInfo()
{
	cout << "����: " << m_cClassName << "   ����: " << m_sStatInfo->m_iLev << "   ���ݷ�: " << m_sStatInfo->m_iAt << "   ����: " << m_sStatInfo->m_iDt
		<< "   ü��: " << m_sStatInfo->m_iHp << "/" << m_sStatInfo->m_iMaxHp
		<< "   ����ġ: " << m_sStatInfo->m_iExp << "/" << m_sStatInfo->m_iExp * m_sStatInfo->m_iLev;
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

