#include <string>
using namespace std;

#include "CGameManager.h"
#include "CSceneManager.h"

int main()
{
	while (true)
	{
		system("cls");
		CSceneManager::Instance()->Update();

		if (CSceneManager::Instance()->GetEScene() == eSCENE::EXIT) break;
	}
}
