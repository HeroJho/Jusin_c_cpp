#include <iostream>
using namespace std;

// 1. while문을 이용하여 2-9단까지 출력하기.
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

		cout << "===== " << i << "단" << " =====" << endl;

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