#include "CTown.h"

void CTown::Update()
{
	int iInput = 0;

	CGameManager::Instance()->PrintPlayerInfo();
	
	cout << "1.���  2.���� >> ";
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
		cout << "�ٽ� �Է��� �ּ���." << endl;
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
