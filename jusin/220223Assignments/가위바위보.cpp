#include <iostream>
#include <time.h>

using namespace std;

// 1.가위바위보
// - 난수 0-2까지 중 하나 생성
// - 출력 1.가위 2.바위 3.보 4.종료
// - 입력한 값과 난수를 비교해서 가위바위보 승, 무, 패를 판별
// - 총 5라운드 실행 후, 승, 무, 패 출력
// - 반복문은 맘대로 선택
int main()
{
	int iRanNum = 0, iChos = 0, iWin = 0, iLose = 0, iDrow = 0;

	cout << "가위바위보 게임!!" << endl;

	srand(unsigned(time(NULL)));
	
	for (int i = 0; i < 5; i++)
	{
		system("pause");
		system("cls");

		iRanNum = rand() % 3 + 1;
		cout << "===== Round " << i + 1 << " =====" << endl;
		cout << "1.가위 2.바위 3.보 4.종료: ";
		cin >> iChos;

		if (4 <= iChos)
			break;

		// 1 < 2 < 3 < 1

		// 같다 = 무승부
		// 나보다 크다 = 졌다
		// 나보다 작다 = 이겼다
		cout << iRanNum << endl;

		// 3 < 1 예외처리
		if (iChos == 1 && iRanNum == 3)
		{
			cout << "승리!" << endl;
			++iWin;
		}
		else if (iChos == 3 && iRanNum == 1)
		{
			cout << "패배!" << endl;
			++iLose;
		}
		else
		{
			if (iChos == iRanNum)
			{
				cout << "무승부!" << endl;
				++iDrow;
			}
			else if (iChos > iRanNum)
			{
				cout << "승리!" << endl;
				++iWin;
			}
			else
			{
				cout << "패배!" << endl;
				++iLose;
			}
		}

	}
	system("cls");

	cout << "승:" << iWin << " 패:" << iLose << " 무:" << iDrow << endl;
}