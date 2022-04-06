#pragma once

#define SAVE_DELETE(p) if(p) {delete p;}

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
enum class FIELD { NONE, TOWN, HUNT, SHOP, IVEN, END };
enum class CLASS { NONE, WOR, MAG, ARCH };

