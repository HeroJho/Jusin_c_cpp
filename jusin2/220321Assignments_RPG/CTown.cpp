#include "CTown.h"

void CTown::Update()
{
	int iInput = 0;

	CGameManager::Instance()->PrintPlayerInfo();
	
	cout << "1.사냥  2.종료 >> ";
	cin >> iInput;

	switch (iInput)
	{
	case 1:
		CSceneManager::Instance()->SetScene(eSCENE::HUNT);
		break;
	case 2:
		CSceneManager::Instance()->SetScene(eSCENE::EXIT);
		break;
	default:
		cout << "다시 입력해 주세요." << endl;
		system("pause");
		break;
	}

}

CTown::CTown()
{
}

CTown::~CTown()
{
}
