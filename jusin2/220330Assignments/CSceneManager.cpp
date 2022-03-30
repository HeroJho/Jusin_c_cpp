#include "pch.h"
#include "CSceneManager.h"

#include "CTown.h"
#include "CDungun.h"
#include "CShop.h"

CPlayer* CSceneManager::m_cPlayer = nullptr;
SCENE CSceneManager::m_eCurScene = SCENE::NONE;
SCENE CSceneManager::m_ePreScene = SCENE::NONE;

CSceneManager::CSceneManager()
{
	m_cScenes[SCENE::TOWN] = new CTown;
	m_cScenes[SCENE::DUNGUN] = new CDungun;
	m_cScenes[SCENE::SHOP] = new CShop;

	MakePlayer();

	ChangeScene(SCENE::TOWN);
}
CSceneManager::~CSceneManager()
{
	SAFE_DELETE(m_cPlayer);

	SAFE_DELETE(m_cScenes[SCENE::TOWN]);
	SAFE_DELETE(m_cScenes[SCENE::DUNGUN]);
	SAFE_DELETE(m_cScenes[SCENE::SHOP]);
}

CPlayer* CSceneManager::Get_Player()
{
	return m_cPlayer;
}

void CSceneManager::ChangeScene(SCENE _eScene)
{
	m_ePreScene = m_eCurScene;
	m_eCurScene = _eScene;
}

void CSceneManager::MakePlayer()
{

}
