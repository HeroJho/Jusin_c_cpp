#pragma once

#include "CPlayer.h"
#include "CScene.h"

class CSceneManager
{
private:
	static CPlayer* m_cPlayer;
	static SCENE m_eCurScene;
	static SCENE m_ePreScene;

	CScene* m_cScenes[SCENE::COUNT];
	
public:
	void Update();

	static CPlayer* Get_Player();
	static void ChangeScene(SCENE _eScene);

private:
	void MakePlayer();

public:
	CSceneManager();
	~CSceneManager();

};

