#include <iostream>
#include <time.h>

using namespace std;

// 1.����������
// - ���� 0-2���� �� �ϳ� ����
// - ��� 1.���� 2.���� 3.�� 4.����
// - �Է��� ���� ������ ���ؼ� ���������� ��, ��, �и� �Ǻ�
// - �� 5���� ���� ��, ��, ��, �� ���
// - �ݺ����� ����� ����
int main()
{
	int iRanNum = 0, iChos = 0, iWin = 0, iLose = 0, iDrow = 0;

	cout << "���������� ����!!" << endl;

	srand(unsigned(time(NULL)));
	
	for (int i = 0; i < 5; i++)
	{
		system("pause");
		system("cls");

		iRanNum = rand() % 3 + 1;
		cout << "===== Round " << i + 1 << " =====" << endl;
		cout << "1.���� 2.���� 3.�� 4.����: ";
		cin >> iChos;

		if (4 <= iChos)
			break;

		// 1 < 2 < 3 < 1

		// ���� = ���º�
		// ������ ũ�� = ����
		// ������ �۴� = �̰��
		cout << iRanNum << endl;

		// 3 < 1 ����ó��
		if (iChos == 1 && iRanNum == 3)
		{
			cout << "�¸�!" << endl;
			++iWin;
		}
		else if (iChos == 3 && iRanNum == 1)
		{
			cout << "�й�!" << endl;
			++iLose;
		}
		else
		{
			if (iChos == iRanNum)
			{
				cout << "���º�!" << endl;
				++iDrow;
			}
			else if (iChos > iRanNum)
			{
				cout << "�¸�!" << endl;
				++iWin;
			}
			else
			{
				cout << "�й�!" << endl;
				++iLose;
			}
		}

	}
	system("cls");

	cout << "��:" << iWin << " ��:" << iLose << " ��:" << iDrow << endl;
}