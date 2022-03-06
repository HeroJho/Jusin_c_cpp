#include <iostream>
#include <time.h>
using namespace std;

// �߱� ����
// - 1-9���� ������ ���ڸ� 3���� ����
// - ������ ���Ѵ�
// - �ߺ� üũ x
// - �Է��ϴ� ���ڿ� ������ ������ ���� �ڸ��� ��ġ�ϸ� ��Ʈ����ũ, ���� ��ġ�ϸ� ��
// - �� ȸ �Է� �� �� ��Ʈ����ũ �� �� ����Ѵ�
// - 3��Ʈ����ũ�� ������ ���� �¸�
// - 9������� ����, 3��Ʈ����ũ�� ������� �й�
// ex)
// ����		2	8	5
// 1ȸ��:	1	2	3 -> 1��
// 2ȸ��:	2	4	6 -> 1��Ʈ����ũ
// 3ȸ��:	2	5	6 -> 1��Ʈ����ũ 1��
// 4ȸ��:	2	5	8 -> 1��Ʈ����ũ 2��
// 5ȸ��:	5	2	8 -> 3��
void main()
{
	int iRound = 1;
	int iRandNum = 0;
	int iArray[3] = {};
	int iInputArray[3] = {};
	bool canStore = true;
	int st = 0, bol = 0;
	srand(unsigned(time(NULL)));

	// ���� �̱�
	for (int i = 0; i < 3;)
	{
		canStore = true;
		iRandNum = rand() % 9 + 1;
		for (int j = 0; j < i; j++)
		{
			if (iArray[j] == iRandNum)
				canStore = false;
		}
		if (!canStore)
			continue;
		iArray[i] = iRandNum;
		i++;
	}

	cout << "����:  ";
	for (int i = 0; i < 3; i++)
	{
		cout << iArray[i] << " ";
	}
	cout << endl;

	while (iRound < 10)
	{

		cout << iRound << "ȸ��: ";
		for (int i = 0; i < 3; i++)
		{
			cin >> iInputArray[i];
		}

		// �� �ֳ�
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (i == j && iArray[i] == iInputArray[j])
					st++;
				else if (iArray[i] == iInputArray[j])
					bol++;
			}
		}
		cout << ": " << bol << "��, " << st << "��Ʈ����ũ" << endl;
		if (st == 3)
		{
			cout << "�¸�!!!" << endl;
			return;
		}
		bol = 0;
		st = 0;

		iRound++;
	}
	cout << "����..." << endl;
}