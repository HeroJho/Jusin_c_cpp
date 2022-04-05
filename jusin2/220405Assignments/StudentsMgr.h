#pragma once

#include "StudentData.h"

class StudentsMgr
{
private:
	vector<StudentData*> m_vecData;

public:
	void CreateData();
	void FindAndPrint();
	void Remove();
	void PrintAll();

private:
	void push(StudentData* _cData);
	int findIndex(const string& _sName);

public:
	StudentsMgr();
	~StudentsMgr();

};

