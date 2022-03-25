#pragma once

#include "CTown.h"
#include "CHunt.h"
#include "CShop.h"
#include "CPlayer.h"
#include "CMonster.h"

class CGameManager
{
private:
	static FIELD m_eCurField;
	static FIELD m_ePreField;
	CTown* m_cTown;
	CHunt* m_cHunt;
	CShop* m_cShop;

	static CPlayer* m_cPlayer;

public:
	void Update();
	void Login();

public:
	static void Set_CurField(FIELD _eCurField);
	static FIELD Get_CurField();
	static FIELD Get_PreField();

	static CPlayer* Get_Player();

public:
	CGameManager();
	~CGameManager();
};

