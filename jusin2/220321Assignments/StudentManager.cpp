#include "StudentManager.h"
#include <iostream>
using namespace std;

void StudentManager::Init()
{
	m_iLenth = 0;
	m_iCapacity = LEAST;
	m_cLists = new Student[m_iCapacity];
}

void StudentManager::Add(Student _cStudent)
{
	if (m_iLenth >= m_iCapacity)
	{
		m_iCapacity *= 2;
		Student* temp = new Student[m_iCapacity];
		
		for (int i = 0; i < m_iLenth; ++i)
		{
			temp[i] = m_cLists[i];
		}

		delete[] m_cLists;

		m_cLists = temp;
	}

	m_cLists[m_iLenth] = _cStudent;
	++m_iLenth;
	
}

Student StudentManager::Make()
{
	Student s;
	string name = "";
	float temp = 0;

	cout << "�̸�: ";
	cin >> name;
	s.Set_Name(name);

	cout << "����: ";
	cin >> temp;
	s.Set_Kor(temp);

	cout << "����: ";
	cin >> temp;
	s.Set_En(temp);

	cout << "����: ";
	cin >> temp;
	s.Set_Math(temp);

	return s;
}

Student* StudentManager::Surch(string name)
{
	for (int i = 0; i < m_iLenth; i++)
	{
		if (m_cLists[i].Get_Name() == name)
			return &m_cLists[i];
	}

	return nullptr;
}

void StudentManager::FindAndPrintInfo()
{
	string name = "";
	cout << "ã���� �̸��� �Է��ϼ���. >> ";
	cin >> name;

	Student* s = Surch(name);
	if (s == nullptr)
		cout << name << " >> ��Ī�Ǵ� �л��� �����ϴ�." << endl;
	else
		s->PrintInfo();
}

void StudentManager::PrintAllInfo()
{
	cout << "====================" << endl;
	for (int i = 0; i < m_iLenth; i++)
	{
		cout << i+1 << ".";
		m_cLists[i].PrintInfo();
	}
	cout << "====================" << endl;
}

void StudentManager::PrintMenu()
{
	cout << "1.�߰�  2.��ü ���  3.ã��  4.����" << endl;
}

void StudentManager::DeleteManager()
{
	if (m_cLists != nullptr)
		delete[] m_cLists;
}
