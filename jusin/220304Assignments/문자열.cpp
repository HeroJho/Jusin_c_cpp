#include <iostream>
using namespace std;

const int MAX_LEN = 100;
void ReverseString(char* p, int iLen)
{
	for (int i = iLen; i >= 0; i--)
	{
		cout << p[i];
	}
}
int GetLenth(char* c)
{
	int iLen = 0;
	for (iLen = 0; c[iLen] != '\0'; iLen++)
		iLen++;
	return iLen;
}

void main()
{
	char cInput[MAX_LEN] = { 0 };
	int iLen = 0;

	cout << "문자열을 입력해 주세요. >> ";
	cin >> cInput;
	
	iLen = GetLenth(cInput);
	cout << iLen << endl;

	ReverseString(cInput, iLen);
}