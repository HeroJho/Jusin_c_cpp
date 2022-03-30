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
	cout << "이름: " << m_sStatInfo->m_cName << "	레벨: " << m_sStatInfo->m_iLevel
		<< "	공격력: " << m_sStatInfo->m_iAt << "		방어력 " << m_sStatInfo->m_iDt
		<< "	체력: " << m_sStatInfo->m_iHp << '/' << m_sStatInfo->m_iMaxHp
		<< "	경험치: " << m_sStatInfo->m_iExp << '/' << m_sStatInfo->m_iLevel * 10;
}