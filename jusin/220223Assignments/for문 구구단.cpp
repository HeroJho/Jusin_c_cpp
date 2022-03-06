#include <iostream>

using namespace std;

// 2. for문을 이용해서 구구단 2-9단 출력
// - 2중 폴문 이용
int main()
{
	for (int i = 2; i < 10; i++)
	{
		for (int j = 1; j < 10; j++)
		{
			cout << i << "*" << j << " = " << i * j << endl;
		}
		cout << endl << endl;
	}
}