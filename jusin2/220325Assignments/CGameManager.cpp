#include "pch.h"
#include "CGameManager.h"

FIELD CGameManager::m_eCurField = FIELD::NONE;
FIELD CGameManager::m_ePreField = FIELD::NONE;
CPlayer* CGameManager::m_cPlayer = nullptr;

CGameManager::CGameManager()
	:m_cTown(nullptr), m_cHunt(nullptr), m_cShop(nullptr)
{
	m_cTown = new CTown();
	m_cHunt = new CHunt();
	m_cShop = new CShop();
}
CGameManager::~CGameManager()
{
	if(m_cTown != nullptr)
		delete m_cTown;
	if (m_cHunt != nullptr)
		delete m_cHunt;
	if (m_cShop != nullptr)
		delete m_cShop;
}

void CGameManager::Set_CurField(FIELD _eCurField)
{
	m_ePreField = m_eCurField;
	m_eCurField = _eCurField;
}
FIELD CGameManager::Get_CurField()
{
	return m_eCurField;
}
FIELD CGameManager::Get_PreField()
{
	return m_ePreField;
}

CPlayer* CGameManager::Get_Player()
{
	return m_cPlayer;
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
	Set_CurField(FIELD::TOWN);
}
void CGameManager::Update()
{
	system("cls");
	switch (m_eCurField)
	{
	case FIELD::TOWN:
		m_cTown->Update();
		break;
	case FIELD::HUNT:
		break;
	case FIELD::SHOP:
		break;
	default:
		break;
	}
}


