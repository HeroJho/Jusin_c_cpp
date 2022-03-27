#include "pch.h"
#include "CHunt.h"
#include "CGameManager.h"

CHunt::CHunt()
{

}
CHunt::~CHunt()
{

}


void CHunt::Update()
{
	int iInput = 0;

	do
	{
		cout << "몬스터를 선택하세요." << endl;
		cout << "1.슬라임  2.주황버섯  3.오크  4.마을로		>> ";
		cin >> iInput;

		if (1 > iInput || 4 < iInput)
		{
			cout << "다시 입력해 주세요!" << endl;
			system("pause");
			continue;
		}

		break;
	} while (true);

	if (iInput == 4) {
		CGameManager::Set_CurField(CGameManager::Get_PreField());
		return;
	}
		
	CMonster _cMonster(iInput);

	do
	{
		system("cls");

		cout << "=========================" << endl;
		CGameManager::Get_Player()->PrintInfo();
		cout << endl;
		cout << "=========================" << endl;
		_cMonster.PrintInfo();
		cout << endl;
		cout << "=========================" << endl;
		cout << endl;


		cout << "1.공격  2.도망		>> ";
		cin >> iInput;

		if (1 > iInput || 2 < iInput)
		{
			cout << "다시 입력해 주세요!" << endl;
			system("pause");
			continue;
		}
		if (iInput == 2) {
			CGameManager::Set_CurField(CGameManager::Get_PreField());
			return;
		}


		if (_cMonster.Attacked(CGameManager::Get_Player()->Get_At()))
		{
			cout << "승리!" << endl;
			system("pause");
			CGameManager::Set_CurField(FIELD::TOWN);
			return;
		}
		if (CGameManager::Get_Player()->Attacked(_cMonster.Get_At()))
		{
			cout << "패배!" << endl;
			system("pause");
			CGameManager::Set_CurField(FIELD::TOWN);
			return;
		}


	} while (true);
}