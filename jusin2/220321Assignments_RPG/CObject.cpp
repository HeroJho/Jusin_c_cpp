#include "CObject.h"

CObject::CObject()
{
}

CObject::~CObject()
{
}

void CObject::PrintInfo()
{
	cout << "����: " << m_iLev << " ���ݷ�: " << m_iAt << " ü��: " << m_iHp << "/" << m_iMaxHp << endl;
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
