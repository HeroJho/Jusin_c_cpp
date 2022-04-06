#include "pch.h"
#include "CGameManager.h"
#include "CSceneManager.h"

int main()
{
	CGameManager GM;

	GM.Login();

	while (CGameManager::Get_SceneMgr()->Get_CurField() != FIELD::NONE)
		GM.Update();

}
