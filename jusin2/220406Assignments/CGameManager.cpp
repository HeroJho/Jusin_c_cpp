#include "pch.h"
#include "CGameManager.h"
#include "CSceneManager.h"

#include "CPlayer.h"

CPlayer* CGameManager::m_cPlayer = nullptr;
CSceneManager* CGameManager::m_cSceneMgr = nullptr;

CGameManager::CGameManager()
{
	m_cSceneMgr = new CSceneManager;
}
CGameManager::~CGameManager()
{
	SAVE_DELETE(m_cSceneMgr)
}

void CGameManager::Login()
{
	int iInput = 0;

	do
	{
		system("cls");

		cout << "ĳ���͸� ������ �ּ���." << endl;
		cout << "1.����  2.������  3.�ü�	>> ";
		cin >> iInput;

		if (1 > iInput || 3 < iInput)
		{
			cout << "�ٽ� �Է��� �ּ���!" << endl;
			system("pause");
			continue;
		}

		break;
	} while (true);

	m_cPlayer = new CPlayer(CLASS(iInput));
	Get_SceneMgr()->Set_CurField(FIELD::TOWN);
}
void CGameManager::Update()
{
	m_cSceneMgr->Update();
}


