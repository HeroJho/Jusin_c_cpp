#pragma once


class CPlayer;
class CSceneManager;


class CGameManager
{

private:
	static CPlayer* m_cPlayer;
	static CSceneManager* m_cSceneMgr;

public:
	void Update();
	void Login();

public:
	static const CPlayer* Get_Player() { return m_cPlayer; }
	static const CSceneManager* Get_SceneMgr() { return m_cSceneMgr; }

public:
	CGameManager();
	~CGameManager();
};

