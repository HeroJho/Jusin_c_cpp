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
	cout << "ĳ���͸� �����ϼ���." << endl;
	cout << "1.����  2.�ü�  3.���� >> ";
	cin >> iInput;

	if (iInput < 1 || iInput > 3)
	{
		cout << "�ٽ� �Է��ϼ���." << endl;
		system("pause");
		return;
	}

	CGameManager::Instance()->MakePlayer(iInput);
	CSceneManager::Instance()->SetScene(eSCENE::TOWN);
}
