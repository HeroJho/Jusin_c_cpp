#include <iostream>

using namespace std;

// 3. for���� �̿��ؼ� �ܰ� ���� �Է� �޾Ƽ� ������ ���
// - 5�� 6�� �Է��ϸ� >> 2-5�ܱ��� 6�� ���
int main()
{
	int iDan = 0, iMul = 0;

	cout << "��: ";
	cin >> iDan;
	cout << "��: ";
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