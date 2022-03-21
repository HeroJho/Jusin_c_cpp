#include "CHunt.h"

void CHunt::Update()
{
	int iInput = 0;
	cout << "몬스터를 선택하세요! >> " << endl;
	cout << "1.주황버섯  2.뿔버섯  3.머쉬맘  4.마을 >> ";
	cin >> iInput;

	if (iInput < 1 || iInput > 4)
	{
		cout << "다시 입력하세요." << endl;
		system("pause");
		return;
	}
	
	if (iInput == 4) {
		CSceneManager::Instance()->SetScene(eSCENE::TOWN);
		return;
	}

	CPlayer* cPlayer = CGameManager::Instance()->GetPlayer();
	CMonster* cMonster = new CMonster(iInput);

	while (true)
	{
		system("cls");
		cPlayer->PrintInfo();
		cMonster->PrintInfo();
		cout << "1.공격  2.도망 ";
		cin >> iInput;
		if (iInput < 1 || iInput > 2)
		{
			cout << "다시 입력하세요." << endl;
			system("pause");
			continue;
		}

		if (iInput == 2)
			break;

		if (cMonster->Attacked(cPlayer)) {
			cout << "승리!" << endl;
			cPlayer->GetExp(10);
			system("pause");
			break;
		}
		if (cPlayer->Attacked(cMonster)) {
			cout << "패배!" << endl;
			system("pause");
			break;
		}
	}

	CSceneManager::Instance()->SetScene(eSCENE::TOWN);
	delete cMonster;
}

CHunt::CHunt()
{
}

CHunt::~CHunt()
{
}
