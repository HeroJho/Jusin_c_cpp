#include <iostream>

using namespace std;


int main()
{
	int iHigh = 5;

	for (int i = 0; i < iHigh; i++)
	{
		for (int j = 0; j < i + 1; j++)
		{
			cout << "*";
		}
		cout << endl;
	}

	cout << endl;

	for (int i = 0; i < iHigh; i++)
	{
		for (int j = 0; j < iHigh - i; j++)
		{
			cout << "*";
		}
		cout << endl;
	}

	cout << endl;

	for (int i = 0; i < iHigh; i++)
	{
		for (int k = 1; k < iHigh - i; k++)
		{
			cout << " ";
		}
		for (int j = 0; j < i + 1; j++)
		{
			cout << "*";
		}
		cout << endl;
	}

	cout << endl;

	for (int i = 0; i < iHigh; i++)
	{
		for (int k = 0; k < i; k++)
		{
			cout << " ";
		}
		for (int j = 0; j < iHigh - i; j++)
		{
			cout << "*";
		}
		cout << endl;
	}

}