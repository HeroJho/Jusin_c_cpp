#include <iostream>
using namespace std;

// 2중 for문과 배열을 이용하여 다음처럼 출력해라
// 1  2  3  4  5 
// 6  7  8  9  10
// 11 12 13 14 15
// 16 17 18 19 20
// 21 22 23 24 25
void main()
{
	int iArray[25] = {0};

	for (int i = 0; i < 25; i++)
	{
		iArray[i] = i + 1;
	}

	for (int i = 0; i < 5; i++)
	{
		for (int j = i*5; j < i*5 + 5; j++)
		{
			if (iArray[j] < 10)
				cout << " " << iArray[j] << " ";
			else
				cout << iArray[j] << " ";
		}
		cout << "\n" << endl;
	}


	// 자주 쓰이는 패턴
	// 규칙을 찾는 과정 중요!!
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			int iIndex = i * 5 + j;

			cout << iArray[iIndex] << "\t";
		}
		cout << endl;
	}
}