#include <iostream>
#include <time.h>
using namespace std;

// 4. Ȧ¦ ���� �����
//  - ������ �̾Ƴ��� �� ���ڰ� Ȧ���� ¦���� �Ǻ��ϴ� ����
//  - ������ 1-10���� �� �ϳ��� ���� (������ �̹� ����)
//  - 1.Ȧ�� 2.¦�� 3.����
//  - �� 5���带 �ǽ��Ͽ� ������ ���� ����� �� �� �� �и� ���
//  - �Ŷ��帶�� ������ ���� �̴´�.
int main()
{
	int iRandNum = 0, iAns = 0, iRound = 0, iPoint = 0;

	cout << "-_-_-Ȧ¦����!-_-_-" << endl;

	while (true)
	{
		system("pause");
		system("cls");
		++iRound;
		if (5 < iRound)
			break;

		cout << "=====Round " << iRound << "=====" << endl << endl;
		srand(unsigned(time(NULL)));

		while (true)
		{
			// 0~32767���� >> 1~10����
			iRandNum = rand();
			if (10 < iRandNum)
			{
				iRandNum %= 11;
				if (iRandNum != 0)
					break;
			}
		}

		cout << "����: " << iRandNum << endl;
		cout << "1.Ȧ��  2.¦��  3.����: ";
		cin >> iAns;
		if (3 <= iAns)
			break;

		cout << endl;
		if ((iRandNum % 2 != 0 && iAns == 1) || (iRandNum % 2 == 0 && iAns == 2))
		{
			cout << "���� �Դϴ�!!" << endl;
			++iPoint;
		}
		else
			cout << "���� �Դϴ�..." << endl;
	}

	cout << "���� ����: " << iPoint <<"��, " << (iRound - 1) - iPoint << "��" << endl;
}