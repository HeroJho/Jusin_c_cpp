#include <iostream>
#include "StudentManager.h"
using namespace std;

enum STATE {ADD = 1, PRINT, SURCH, EXIT, NONE};

int main()
{
	int iInput = 0;
	STATE state = NONE;

    StudentManager manager;
    manager.Init();


	while (true)
	{
		manager.PrintMenu();
		cin >> iInput;
		state = (STATE)iInput;

		switch (state)
		{
		case ADD:
			manager.Add(manager.Make());
			break;
		case PRINT:
			manager.PrintAllInfo();
			break;
		case SURCH:
			manager.FindAndPrintInfo();
			break;
		case EXIT:
			return 0;
		default:
			break;
		}
	}

	manager.DeleteManager();
}
