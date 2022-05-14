#include <string>
#include <vector>
#include <iostream>
#include <windows.h>

using namespace std;

class Player
{
public:
	void Update()
	{
		delete this;

		cout << "AAAA" << endl;
	}
};

void main()
{
	Player* p = new Player;

	while (true)
	{
		p->Update();
	}
}





