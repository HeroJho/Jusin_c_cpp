#pragma once
#include <iostream>
using namespace std;

class Student
{
private:
	string m_sName = "";
	float m_fKor = 0;
	float m_fEn = 0;
	float m_fMath = 0;


public:
	void Init(string _sName, float _fKor, float _fEn, float _fMath);

	void Set_Name(string _sName);
	string Get_Name();
	void Set_Kor(float _fKor);
	float Get_Kor();
	void Set_En(float _fKor);
	float Get_En();
	void Set_Math(float _fKor);
	float Get_Math();

	float Get_Total();
	float Get_Avg();

public:
	void PrintInfo();

};

