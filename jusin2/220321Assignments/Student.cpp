#include "Student.h"
#include <iostream>
using namespace std;

void Student::Init(string _sName, float _fKor, float _fEn, float _fMath)
{
	m_sName = _sName;

	m_fKor = _fKor;
	m_fEn = _fEn;
	m_fMath = _fMath;
}

void Student::Set_Name(string _sName)
{
	m_sName = _sName;
}

string Student::Get_Name()
{
	return m_sName;
}

void Student::Set_Kor(float _fKor)
{
	m_fKor = _fKor;
}

float Student::Get_Kor()
{
	return m_fKor;
}

void Student::Set_En(float _fEn)
{
	m_fEn = _fEn;
}

float Student::Get_En()
{
	return m_fEn;
}

void Student::Set_Math(float _fMath)
{
	m_fMath = _fMath;
}

float Student::Get_Math()
{
	return m_fMath;
}

float Student::Get_Total()
{
	return m_fKor + m_fEn + m_fMath;
}
float Student::Get_Avg()
{
	return Get_Total() / 3;
}



void Student::PrintInfo()
{
	cout << "이름: " << m_sName << "  국어: " << m_fKor << "  영어: " << m_fEn << "  수학: " << m_fMath << "  총점: " << Get_Total() << "  평균: " << Get_Avg() << endl;
}
