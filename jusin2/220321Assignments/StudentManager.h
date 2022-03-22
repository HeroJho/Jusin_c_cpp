#pragma once

#include "Student.h"
#include <iostream>

#define LEAST 3

class StudentManager
{
private:
	Student* m_cLists;
	int m_iLenth;
	int m_iCapacity;

public:
	void Init();

	void Add(Student _cStudent);
	Student Make();
	Student* Surch(string name);

public:
	void FindAndPrintInfo();
	void PrintAllInfo();
	
	void PrintMenu();

	void DeleteManager();
};

