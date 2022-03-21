#include "CMonster.h"

CMonster::CMonster(int _iInput)
{
	switch (_iInput)
	{
	case 1:
		m_sName = "��Ȳ����";
		m_iLev = 1;
		m_iMaxHp = 10;
		m_iHp = 10;
		m_iAt = 1;
		break;
	case 2:
		m_sName = "�Թ���";
		m_iLev = 5;
		m_iMaxHp = 50;
		m_iHp = 50;
		m_iAt = 3;
		break;
	case 3:
		m_sName = "�ӽ���";
		m_iLev = 20;
		m_iMaxHp = 100;
		m_iHp = 100;
		m_iAt = 6;
		break;
	}
}

CMonster::~CMonster()
{
}

void CMonster::PrintInfo()
{
	cout << "�̸�: " << m_sName << " ";
	CObject::PrintInfo();
}
