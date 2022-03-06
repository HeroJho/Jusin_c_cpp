#include <iostream>

using namespace std;

void Func(const char* c[])
{
	cout << c << endl;
}

void Func(int** i)
{
	cout << i[0];
}

int main()
{
	const char* arr[3] = { "111", "222", "444" };
	int a = 5;
	int b = 2;
	int c = 1;
	int* arra[3] = { &a, &b, &c };
	Func(arra);

}