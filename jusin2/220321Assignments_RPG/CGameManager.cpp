#include "CGameManager.h"

CGameManager* CGameManager::m_cInstance = nullptr;

CGameManager::CGameManager()
	:m_cPlayer(nullptr)
{
}

CGameManager::~CGameManager()
{
	if (m_cPlayer != nullptr)
		delete m_cPlayer;
}


CPlayer* CGameManager::GetPlayer()
{
	return m_cPlayer;
}

void CGameManager::MakePlayer(int _iInput)
{
	m_cPlayer = new CPlayer(_iInput);
}

void CGameManager::PrintPlayerInfo()
{
	cout << "===============================" << endl;
	m_cPlayer->PrintInfo();
	cout << "===============================" << endl;
}


