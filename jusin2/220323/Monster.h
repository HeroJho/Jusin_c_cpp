#pragma once

class CPlayer;

class CMonster
{
private:
	int			m_iB;
	CPlayer* m_Player;

public:
	void		Print() { cout << m_iB << endl; }
	void		Output(void);

public:
	CMonster();
	~CMonster();
};
