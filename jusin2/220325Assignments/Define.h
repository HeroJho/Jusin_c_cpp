#pragma once

struct StatInfo
{
	int m_iExp;
	int m_iLev;

	int m_iHp;
	int m_iMaxHp;
	int m_iAt;
	int m_iDt;
};

enum class MONSTER { SLIME = 1, MUSHROOM, ORK };
enum class FIELD { NONE, TOWN, HUNT, SHOP };
enum class CLASS{ NONE, WOR, MAG, ARCH};