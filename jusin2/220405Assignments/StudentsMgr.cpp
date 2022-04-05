#include "pch.h"
#include "StudentsMgr.h"

StudentsMgr::StudentsMgr()
	:m_vecData{}
{
}

StudentsMgr::~StudentsMgr()
{
	for (GET_ITER(iter, m_vecData);
		iter != m_vecData.end(); ++iter)
		SAVE_DELETE(*iter)

		m_vecData.clear(); // ��۸�?
}



void StudentsMgr::CreateData()
{
	string sName;
	int iKor = 0;
	int iEng = 0;
	int iMath = 0;

	cout << "�̸� �Է�" << endl;
	cin >> sName;
	cout << "���� ����" << endl;
	cin >> iKor;
	cout << "���� ����" << endl;
	cin >> iEng;
	cout << "���� ����" << endl;
	cin >> iMath;

	StudentData* temp = new StudentData(sName, iKor, iEng, iMath);
	push(temp);
}

void StudentsMgr::FindAndPrint()
{
	string _sName;
	cout << "�̸��� �Է��� �ּ���." << endl;
	cin >> _sName;

	int index = findIndex(_sName);
	if (index == -1)
	{
		cout << "�л��� �����ϴ�." << endl;
		system("pause");
		return;
	}

	GET_ITER(iter, m_vecData);
	iter += index;

	(*(*iter)).PrintInfo();
	system("pause");
}

void StudentsMgr::Remove()
{
	string _sName;
	cout << "�̸��� �Է��� �ּ���." << endl;
	cin >> _sName;

	int index = findIndex(_sName);
	if (index == -1)
	{
		cout << "�л��� �����ϴ�." << endl;
		system("pause");
		return;
	}

	GET_ITER(iter, m_vecData);
	iter += index;

	m_vecData.erase(iter);
	cout << "���������� �����Ǿ����ϴ�." << endl;
	system("pause");
}

void StudentsMgr::PrintAll()
{
	for (GET_ITER(iter, m_vecData);
		iter != m_vecData.end(); ++iter)
	{
		(*iter)->PrintInfo();
	}
	system("pause");
}



void StudentsMgr::push(StudentData* _cData)
{
	m_vecData.push_back(_cData);
}

int StudentsMgr::findIndex(const string& _sName)
{
	int iCount = 0;
	for (GET_ITER(iter, m_vecData);
		iter != m_vecData.end(); ++iter, ++iCount)
	{
		if ((*(*iter)).GetData().m_sName == _sName)
		{
			return iCount;
		}
	}
	return -1;
}
