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

		cout << "캐릭터를 선택해 주세요." << endl;
		cout << "1.전사  2.마법사  3.궁수	>> ";
		cin >> iInput;

		if (1 > iInput || 3 < iInput)
		{
			cout << "다시 입력해 주세요!" << endl;
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


