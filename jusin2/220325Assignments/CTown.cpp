#include "pch.h"
#include "CTown.h"
#include "CGameManager.h"

CTown::CTown()
{

}
CTown::~CTown()
{

}

void CTown::Update()
{
	int iInput = 0;

	CGameManager::Get_Player()->PrintInfo();
	cout << endl << endl;
	cout << "1.사냥터  2.상점  3.종료	>> ";
	cin >> iInput;

	switch (iInput)
	{
	case 1:
		CGameManager::Set_CurField(FIELD::HUNT);
		break;
	case 2:
		CGameManager::Set_CurField(FIELD::SHOP);
		break;
	case 3:
		CGameManager::Set_CurField(FIELD::NONE);
		break;
	default:
		cout << "다시 입력해 주세요." << endl;
		system("pause");
		break;
	}
}