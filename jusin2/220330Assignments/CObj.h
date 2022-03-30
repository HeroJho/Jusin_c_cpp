#pragma once

class CObj abstract
{
protected:
	StatInfo* m_sStatInfo;

public:
	virtual void PrintInfo();

public:
	CObj(string _cName, int _iAt, int _iDt, int _iMaxHp);
	virtual ~CObj();

};

