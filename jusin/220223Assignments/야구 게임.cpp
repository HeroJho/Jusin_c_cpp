#include <iostream>
#include <time.h>
using namespace std;

// 야구 게임
// - 1-9까지 무작위 숫자를 3개를 추출
// - 정렬은 안한다
// - 중복 체크 x
// - 입력하는 숫자와 무작위 숫자의 값과 자리가 일치하면 스트라이크, 값만 일치하면 볼
// - 매 회 입력 후 몇 스트라이크 몇 볼 출력한다
// - 3스트라이크가 나오면 게임 승리
// - 9라운드까지 진행, 3스트라이크를 못만들면 패배
// ex)
// 정답		2	8	5
// 1회차:	1	2	3 -> 1볼
// 2회차:	2	4	6 -> 1스트라이크
// 3회차:	2	5	6 -> 1스트라이크 1볼
// 4회차:	2	5	8 -> 1스트라이크 2볼
// 5회차:	5	2	8 -> 3볼
void main()
{
	int iRound = 1;
	int iRandNum = 0;
	int iArray[3] = {};
	int iInputArray[3] = {};
	bool canStore = true;
	int st = 0, bol = 0;
	srand(unsigned(time(NULL)));

	// 난수 뽑기
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

	cout << "정답:  ";
	for (int i = 0; i < 3; i++)
	{
		cout << iArray[i] << " ";
	}
	cout << endl;

	while (iRound < 10)
	{

		cout << iRound << "회차: ";
		for (int i = 0; i < 3; i++)
		{
			cin >> iInputArray[i];
		}

		// 값 있냐
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
		cout << ": " << bol << "볼, " << st << "스트라이크" << endl;
		if (st == 3)
		{
			cout << "승리!!!" << endl;
			return;
		}
		bol = 0;
		st = 0;

		iRound++;
	}
	cout << "실패..." << endl;
}