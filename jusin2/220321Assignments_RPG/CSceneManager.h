#pragma once

#include "CScene.h"
#include "Define.h"
#include "CLobby.h"
#include "CTown.h"
#include "CHunt.h"

class CSceneManager
{
#pragma region Singleton
private:
	static CSceneManager* m_cInstance;
public:
	static CSceneManager* Instance()
	{
		if (m_cInstance == nullptr)
			m_cInstance = new CSceneManager();

		return m_cInstance;
	}
#pragma endregion

private:
	CScene* m_cCurScene;
	eSCENE m_eCurScene;
	CScene* m_cSceneList[(int)eSCENE::END];


public:
	void SetScene(eSCENE _cScene);
	eSCENE GetEScene();

	void Update();

public:
	CSceneManager();
	~CSceneManager();
};
