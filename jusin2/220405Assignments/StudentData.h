#pragma once

struct Data
{
	string	m_sName;
	int		m_iKor = 0;
	int		m_iEng = 0;
	int		m_iMath = 0;
	int		m_iTotal = 0;
	float	m_fAvg = 0;
};

class StudentData
{
private:
	Data m_sData;

public:
	const Data& GetData() { return m_sData;	}
	void PrintInfo();

public:
	StudentData(string& _sName, int _iKor, int _iEng, int _iMath);
	~StudentData();
};

