#include <iostream>
using namespace std;

// 1. while���� �̿��Ͽ� 2-9�ܱ��� ����ϱ�.
int main()
{
	int i = 1;
	int j = 0;

	while (true)
	{
		++i;
		j = 0;
		if (9 < i)
			break;

		cout << "===== " << i << "��" << " =====" << endl;

		while (true)
		{
			++j;
			if (9 < j)
				break;

			cout << i << " * " << j << " = " << i * j << endl;
		}

		cout << endl << endl;
	}
}