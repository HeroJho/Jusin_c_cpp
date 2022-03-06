#include <iostream>
#include <time.h>
using namespace std;

// 4. 홀짝 게임 만들기
//  - 난수를 뽑아내서 그 숫자가 홀인지 짝인지 판별하는 게임
//  - 난수는 1-10까지 중 하나를 생성 (정답은 이미 보임)
//  - 1.홀수 2.짝수 3.종료
//  - 총 5라운드를 실시하여 마지막 라운드 종료시 몇 승 몇 패를 출력
//  - 매라운드마다 난수를 새로 뽑는다.
int main()
{
	int iRandNum = 0, iAns = 0, iRound = 0, iPoint = 0;

	cout << "-_-_-홀짝게임!-_-_-" << endl;

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
			// 0~32767범위 >> 1~10범위
			iRandNum = rand();
			if (10 < iRandNum)
			{
				iRandNum %= 11;
				if (iRandNum != 0)
					break;
			}
		}

		cout << "문제: " << iRandNum << endl;
		cout << "1.홀수  2.짝수  3.종료: ";
		cin >> iAns;
		if (3 <= iAns)
			break;

		cout << endl;
		if ((iRandNum % 2 != 0 && iAns == 1) || (iRandNum % 2 == 0 && iAns == 2))
		{
			cout << "정답 입니다!!" << endl;
			++iPoint;
		}
		else
			cout << "오답 입니다..." << endl;
	}

	cout << "나의 점수: " << iPoint <<"승, " << (iRound - 1) - iPoint << "패" << endl;
}