#include "pch.h"
#include "CObj.h"


CObj::CObj(string _cName, int _iAt, int _iDt, int _iMaxHp)
{
	m_sStatInfo = new StatInfo(_cName, _iAt, _iDt, _iMaxHp);
}
CObj::~CObj()
{
	SAFE_DELETE(m_sStatInfo);
}

void CObj::PrintInfo()
{
	cout << "�̸�: " << m_sStatInfo->m_cName << "	����: " << m_sStatInfo->m_iLevel
		<< "	���ݷ�: " << m_sStatInfo->m_iAt << "		���� " << m_sStatInfo->m_iDt
		<< "	ü��: " << m_sStatInfo->m_iHp << '/' << m_sStatInfo->m_iMaxHp
		<< "	����ġ: " << m_sStatInfo->m_iExp << '/' << m_sStatInfo->m_iLevel * 10;
}