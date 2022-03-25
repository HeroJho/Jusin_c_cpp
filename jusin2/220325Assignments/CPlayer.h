#pragma once

class CPlayer
{
private:
	StatInfo* m_sStatInfo;
	CLASS m_eClass;
	string m_cClassName;

public:
	void PrintInfo();

public:
	CPlayer(CLASS _eClass);
	~CPlayer();

};

