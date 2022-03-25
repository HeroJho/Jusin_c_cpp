#include "pch.h"
#include "CGameManager.h"

int main()
{
	CGameManager GM;

	GM.Login();

	while (CGameManager::Get_CurField() != FIELD::NONE)
		GM.Update();

}
