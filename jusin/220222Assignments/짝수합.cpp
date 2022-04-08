#include <iostream>
using namespace std;

// 2. do while문을 이용해서 숫자를 입력받고, 짝수인 경우에만 합을 구하는 프로그램 만들기.
int main()
{
	int iSum = 0;
	int iInput = 0;

	do
	{
		cout << "정수를 입력해 주세요!: ";
		cin >> iInput;

		if (iInput == -1)
			break;

		if (iInput % 2 == 0)
			iSum += iInput;

		cout << "짝수의 합: " << iSum << endl;

	} while (true);
	
}