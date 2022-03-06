#include <iostream>
#include <time.h>
using namespace std;

// 로또 만들기
// - 배열을 이용하여 1-45사이의 수중 무작위로 6개 숫자를 5회 출력
// - 같은 회차에서는 절대 중복 번호가 나올 수 없음, 오름차순 정렬(버블 정렬)
void main()
{
	int iArray[6] = {};
	int randNum = 0;
	bool canStore = true;
	srand(unsigned(time(NULL)));
	for (int iCount = 0; iCount < 6;)
	{
		canStore = true;
		// 1. 무작위 뽑는다.
		randNum = rand() % 45 + 1;

		// 같은 번호가 있는지 비교하고 없으면 넣는다
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