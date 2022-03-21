#include "CHunt.h"

void CHunt::Update()
{
	int iInput = 0;
	cout << "���͸� �����ϼ���! >> " << endl;
	cout << "1.��Ȳ����  2.�Թ���  3.�ӽ���  4.���� >> ";
	cin >> iInput;

	if (iInput < 1 || iInput > 4)
	{
		cout << "�ٽ� �Է��ϼ���." << endl;
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
		cout << "1.����  2.���� ";
		cin >> iInput;
		if (iInput < 1 || iInput > 2)
		{
			cout << "�ٽ� �Է��ϼ���." << endl;
			system("pause");
			continue;
		}

		if (iInput == 2)
			break;

		if (cMonster->Attacked(cPlayer)) {
			cout << "�¸�!" << endl;
			cPlayer->GetExp(10);
			system("pause");
			break;
		}
		if (cPlayer->Attacked(cMonster)) {
			cout << "�й�!" << endl;
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
