#include <iostream>

using namespace std;

// 3. for문을 이용해서 단과 곱을 입력 받아서 구구단 출력
// - 5단 6곱 입력하면 >> 2-5단까지 6곱 출력
int main()
{
	int iDan = 0, iMul = 0;

	cout << "단: ";
	cin >> iDan;
	cout << "곱: ";
	cin >> iMul;

	for (int i = 2; i <= iDan; i++)
	{
		for (int j = 1; j <= iMul; j++)
		{
			cout << i << "*" << j << " = " << i * j << endl;
		}
		cout << endl << endl;
	}

}