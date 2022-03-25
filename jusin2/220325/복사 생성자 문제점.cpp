#include "pch.h"

class CName
{
	// ��� ������ �����͸� ������ �ִ��� Ȯ��
	// ������ ������������ Ȯ�� �ʿ���
	// �Ҹ��ڿ��� �ش� ������ �ּҸ� �����ϴ� �ڵ尡 �ִ��� >> ������ �ʿ����
private:
	char* m_pName;

public:
	CName(const char* pName)
	{
		int iLength = strlen(pName);
		m_pName = new char[iLength + 1];
		strcpy_s(m_pName, iLength + 1, pName);
	}

	CName(const CName& pName)
	{
		int iLength = strlen(pName.m_pName);		// ���� ����

		m_pName = new char[iLength + 1];
		strcpy_s(m_pName, iLength + 1, pName.m_pName);
	}

	void Print(int a) const
	{
		cout << m_pName << endl;
	}

	~CName()
	{
		if (m_pName != nullptr)
			delete[] m_pName;
	}
};

void main()
{
	// ���� >> ���� ����� ����(�Ҹ��� ȣ��)
	CName A("hero");
	CName B(A);

	// B�� ����Ʈ ���� �����ڸ� ȣ��
	// �ּҴ� �ּ� ���簡 �Ͼ (���� ���� ������ shallow copy)
	// �� ���� �����Ͱ� ���� ��ü�� �����Ѽ� ����� ����
	
	// �ذ� ���
	// ������ �ٸ� �ּҸ� ����Ű���� ���� �����ڸ� �����Ѵ�.(��ü ����)

	A.Print();
}