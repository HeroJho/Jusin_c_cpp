#include <iostream>
using namespace std;

// 2. do while���� �̿��ؼ� ���ڸ� �Է¹ް�, ¦���� ��쿡�� ���� ���ϴ� ���α׷� �����.
int main()
{
	int iSum = 0;
	int iInput = 0;

	do
	{
		cout << "������ �Է��� �ּ���!: ";
		cin >> iInput;

		if (iInput == -1)
			break;

		if (iInput % 2 == 0)
			iSum += iInput;

		cout << "¦���� ��: " << iSum << endl;

	} while (true);
	
}