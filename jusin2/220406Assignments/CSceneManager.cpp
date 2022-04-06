#include "pch.h"
#include "CSceneManager.h"

#include "CPlayer.h"
#include "CMonster.h"

#include "CTown.h"
#include "CHunt.h"
#include "CShop.h"

FIELD CSceneManager::m_eCurField = FIELD::NONE;
FIELD CSceneManager::m_ePreField = FIELD::NONE;

CSceneManager::CSceneManager()
	:m_vecScene{}
{
	m_vecScene[(int)FIELD::TOWN] = new CTown();
	m_vecScene[(int)FIELD::HUNT] = new CHunt();
	m_vecScene[(int)FIELD::SHOP] = new CShop();
}
CSceneManager::~CSceneManager()
{
	SAVE_DELETE(m_vecScene[(int)FIELD::TOWN])
	SAVE_DELETE(m_vecScene[(int)FIELD::HUNT])
	SAVE_DELETE(m_vecScene[(int)FIELD::SHOP])
}

void CSceneManager::Set_CurField(FIELD _eCurField)
{
	m_ePreField = m_eCurField;
	m_eCurField = _eCurField;
}
FIELD CSceneManager::Get_CurField()
{
	return m_eCurField;
}
FIELD CSceneManager::Get_PreField()
{
	return m_ePreField;
}

void CSceneManager::Update()
{
	system("cls");

	m_vecScene[(int)m_eCurField]->Update();

	//switch (m_eCurField)
	//{
	//case FIELD::TOWN:
	//	m_cTown->Update();
	//	break;
	//case FIELD::HUNT:
	//	m_cHunt->Update();
	//	break;
	//case FIELD::SHOP:
	//	m_cShop->Update();
	//	break;
	//case FIELD::IVEN:
	//	CGameManager::m_cPlayer->PrintInvenInfos();
	//	CGameManager::Set_CurField(CGameManager::Get_PreField());
	//	break;
	//default:
	//	break;
	//}
}
