#include <iostream>
using namespace std;

// Ű����-�ڷ����� �̸�
struct tagInfo   
{
	bool bChoice;
	char szName[64];	// 
	int iA;				// 12/16
	float fB;			// 16/12
	double dbTemp;		// 8
};
struct Player
{
	char D[26];	// 48/46
	int hp;		// 24/20
	float A;	// 16/16
	float B;	// 16/12
	double C;	// 8/8
};

struct tegTemp
{
	char cName;
	short sBB;
	int iAA;
	long long llCC;

	tagInfo tInfo;	// ����� ���� �ڷ����� ����ü �޸� �Ҵ� ��å�� ������ �ʴ´�.
};

void main()
{
	// ����ü : ���� �ڷ����� �ѵ� ��� �����ϴ� ����� ���� �ڷ���
	// ����� ���� �ڷ���: ����ڰ� ���� �ڷ����� ����� ����Ѵٴ� ��, �⺻ �ڷ����� �����ؼ�
	//    �� ����ü, ����ü, ����ü
	//    �� c++�� Ŭ���� �߰�

	{
		// ����ü ����
		tagInfo tInfo;

		cout << "�̸� �Է� : ";
		cin >> tInfo.szName;		// . ������� ������

		cout << "int�� ���� �Է�: ";
		cin >> tInfo.iA;

		cout << tInfo.szName << endl;
		cout << tInfo.iA << endl;
	}

	{
		// ����ü �ʱ�ȭ
		// ��� ������ ����� ������ �ʱ�ȭ
		tagInfo tInfo = { "ȫ�浿", 100, 6.27 };
		tagInfo tInfo2 = {  };
		cout << tInfo.szName << endl;
	}

	{
		// ����ü ũ��
		// �޸��Ҵ��� �� ��� �ڷ����� ���� ū �ڷ����� �������� �޸� ���� ��´�.
		// �޸� ���� ��� ������ �Ҵ��ϰ� �����ϸ� �޸� ����ŭ �� �Ҵ�.
		// �޸� ���� �⺻�ڷ����� �ش�ȴ�.
		tagInfo tInfo = {};
		cout << sizeof(tagInfo);
	}

	{
		// ����ü�� ������ ����! �Ȱ��� 4����Ʈ
		tagInfo tInfo = {};
		tagInfo* ptInfo = &tInfo;
		
		(*ptInfo).fB;
		ptInfo->fB;
	}
}

// ����: ���� ���α׷� ����ü ����ؼ� �����