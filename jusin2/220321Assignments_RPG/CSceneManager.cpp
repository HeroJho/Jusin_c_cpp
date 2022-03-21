#include "CSceneManager.h"

CSceneManager* CSceneManager::m_cInstance = nullptr;

CSceneManager::CSceneManager()
{
	m_cSceneList[(int)eSCENE::LOBBY] = new CLobby();
	m_cSceneList[(int)eSCENE::TOWN] = new CTown();
	m_cSceneList[(int)eSCENE::HUNT] = new CHunt();

	SetScene(eSCENE::LOBBY);
	m_eCurScene = eSCENE::LOBBY;
}

CSceneManager::~CSceneManager()
{
	delete m_cSceneList[(int)eSCENE::LOBBY];
	delete m_cSceneList[(int)eSCENE::TOWN];
	delete m_cSceneList[(int)eSCENE::HUNT];
}


void CSceneManager::SetScene(eSCENE _eScene)
{
	m_cCurScene = m_cSceneList[(int)_eScene];
	m_eCurScene = _eScene;
}

eSCENE CSceneManager::GetEScene()
{
	return m_eCurScene;
}

void CSceneManager::Update()
{
	m_cCurScene->Update();
}
