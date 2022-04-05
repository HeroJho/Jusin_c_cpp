#include "pch.h"
#include "StudentData.h"


StudentData::StudentData(string& _sName, int _iKor, int _iEng, int _iMath)
{
	m_sData.m_sName = _sName;
	m_sData.m_iKor = _iKor;
	m_sData.m_iEng = _iEng;
	m_sData.m_iMath = _iMath;
	m_sData.m_iTotal = _iKor + _iEng + _iMath;
	m_sData.m_fAvg = m_sData.m_iTotal / 3.f;
}

StudentData::~StudentData()
{

}


void StudentData::PrintInfo()
{
	cout << "�̸�: " << m_sData.m_sName << "   ����: " << m_sData.m_iKor
		<< "   ����: " << m_sData.m_iEng
		<< "   ����: " << m_sData.m_iMath
		<< "   ����: " << m_sData.m_iTotal
		<< "   ���: " << m_sData.m_fAvg
		<< endl;
}
