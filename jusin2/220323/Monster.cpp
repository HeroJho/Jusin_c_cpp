#include "pch.h"
#include "Monster.h"
#include "Player.h"

CMonster::CMonster()
{
	m_iB = 20;
}

CMonster::~CMonster()
{
}

void CMonster::Output(void)
{
	m_Player = new CPlayer;
	m_Player->Render();
}