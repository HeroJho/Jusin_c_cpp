#include <iostream>
#include <time.h>
using namespace std;

// �ζ� �����
// - �迭�� �̿��Ͽ� 1-45������ ���� �������� 6�� ���ڸ� 5ȸ ���
// - ���� ȸ�������� ���� �ߺ� ��ȣ�� ���� �� ����, �������� ����(���� ����)
void main()
{
	int iArray[6] = {};
	int randNum = 0;
	bool canStore = true;
	srand(unsigned(time(NULL)));
	for (int iCount = 0; iCount < 6;)
	{
		canStore = true;
		// 1. ������ �̴´�.
		randNum = rand() % 45 + 1;

		// ���� ��ȣ�� �ִ��� ���ϰ� ������ �ִ´�
		for (int j = 0; j < iCount+1; j++)
		{
			if (iArray[j] == randNum)
				canStore = false;
		}
		if (!canStore)
			continue;

		iArray[iCount] = randNum;
		iCount++;
	}

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5-i; j++)
		{
			if (iArray[j] > iArray[j + 1])
			{
				int temp = iArray[j];
				iArray[j] = iArray[j + 1];
				iArray[j + 1] = temp;
			}
		}
	}

	for (int i = 0; i < 5; i++)
	{
		cout << iArray[i] << endl;
	}
}