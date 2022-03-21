#include "CPlayer.h"

CPlayer::CPlayer(int _iInput)
	:m_iExp(0)
{
	m_iLev = 1;

	switch (_iInput)
	{
	case 1:
		m_sName = "전사";
		m_iMaxHp = 100;
		m_iHp = 100;
		m_iAt = 1;
		break;
	case 2:
		m_sName = "궁수";
		m_iMaxHp = 50;
		m_iHp = 50;
		m_iAt = 3;
		break;
	case 3:
		m_sName = "도적";
		m_iMaxHp = 25;
		m_iHp = 25;
		m_iAt = 6;
		break;
	}
}

CPlayer::~CPlayer()
{
}

void CPlayer::PrintInfo()
{
	cout << "직업: " << m_sName << " 경험치: " << m_iExp << "/" << m_iLev*10 << " ";
	CObject::PrintInfo();
}

void CPlayer::GetExp(int _iValue)
{
	m_iExp += _iValue;
	if (m_iExp >= m_iLev * 10) {
		++m_iLev;
		m_iExp = 0;
	}
}
