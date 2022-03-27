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
		cout << "���͸� �����ϼ���." << endl;
		cout << "1.������  2.��Ȳ����  3.��ũ  4.������		>> ";
		cin >> iInput;

		if (1 > iInput || 4 < iInput)
		{
			cout << "�ٽ� �Է��� �ּ���!" << endl;
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


		cout << "1.����  2.����		>> ";
		cin >> iInput;

		if (1 > iInput || 2 < iInput)
		{
			cout << "�ٽ� �Է��� �ּ���!" << endl;
			system("pause");
			continue;
		}
		if (iInput == 2) {
			CGameManager::Set_CurField(CGameManager::Get_PreField());
			return;
		}


		if (_cMonster.Attacked(CGameManager::Get_Player()->Get_At()))
		{
			cout << "�¸�!" << endl;
			system("pause");
			CGameManager::Set_CurField(FIELD::TOWN);
			return;
		}
		if (CGameManager::Get_Player()->Attacked(_cMonster.Get_At()))
		{
			cout << "�й�!" << endl;
			system("pause");
			CGameManager::Set_CurField(FIELD::TOWN);
			return;
		}


	} while (true);
}