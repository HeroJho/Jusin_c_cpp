#include "pch.h"
#include "Player.h"
#include "Monster.h"


CPlayer::CPlayer()
{
	m_iA = 10;
}


CPlayer::~CPlayer()
{
}

void CPlayer::Draw(void)
{
	m_pMonster = new CMonster;
	m_pMonster->Print();
}
