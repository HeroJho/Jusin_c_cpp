#include "CLobby.h"

CLobby::CLobby()
{
}

CLobby::~CLobby()
{
}

void CLobby::Update()
{
	int iInput = 0;
	cout << "캐릭터를 선택하세요." << endl;
	cout << "1.전사  2.궁수  3.도적 >> ";
	cin >> iInput;

	if (iInput < 1 || iInput > 3)
	{
		cout << "다시 입력하세요." << endl;
		system("pause");
		return;
	}

	CGameManager::Instance()->MakePlayer(iInput);
	CSceneManager::Instance()->SetScene(eSCENE::TOWN);
}
