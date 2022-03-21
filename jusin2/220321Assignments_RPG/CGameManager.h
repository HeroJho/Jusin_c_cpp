#pragma once

#include "CPlayer.h"
#include "CMonster.h"
#include <iostream>
using namespace std;

class CGameManager
{
#pragma region Singleton
private:
	static CGameManager* m_cInstance;
public:
	static CGameManager* Instance()
	{
		if (m_cInstance == nullptr)
			m_cInstance = new CGameManager();

		return m_cInstance;
	}
#pragma endregion

private:
	CPlayer* m_cPlayer;


public:
	CPlayer* GetPlayer();

	void MakePlayer(int _iInput);
	void PrintPlayerInfo();


public:
	CGameManager();
	~CGameManager();

};


