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
	cout << "이름: " << m_sData.m_sName << "   국어: " << m_sData.m_iKor
		<< "   영어: " << m_sData.m_iEng
		<< "   수학: " << m_sData.m_iMath
		<< "   합점: " << m_sData.m_iTotal
		<< "   평균: " << m_sData.m_fAvg
		<< endl;
}
