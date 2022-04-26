#include "pch.h"
#include <string>
#include <list>
#include <windows.h>

using namespace std;

int main()
{
	float PreCount = 0;
	float Delay = 1000;

	PreCount =  GetTickCount();

	while (true)
	{
		if (PreCount + Delay < GetTickCount())
		{
			cout << "Hello World" << endl;
			CurCount = GetTickCount();
		}
	}

    return 0;
}