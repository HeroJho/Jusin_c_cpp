#pragma once

class CMonster
{
private:
	StatInfo* m_sStatInfo;

public:
	void PrintInfo();

public:
	bool Attacked(int _iDamage);
	int Get_At();

public:
	CMonster(int _sValue);
	~CMonster();

};

