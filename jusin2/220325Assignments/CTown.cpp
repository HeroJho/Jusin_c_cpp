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
	cout << "1.�����  2.����  3.����	>> ";
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
		cout << "�ٽ� �Է��� �ּ���." << endl;
		system("pause");
		break;
	}
}