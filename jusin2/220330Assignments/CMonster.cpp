#include "pch.h"
#include "CMonster.h"

CMonster::CMonster(string _cName, int _iAt, int _iDt, int _iMaxHp)
	: CObj(_cName, _iAt, _iDt, _iMaxHp)
{
}
CMonster::~CMonster()
{

}

void CMonster::DieSound()
{
	cout << "³ª " << m_sStatInfo->m_cName << ", Á×À»°Ô~" << endl;
}