#pragma once
class CItem
{
private:
	int m_iId;
	string m_cName;

public:
	void PrintInfo();

public:
	CItem();
	CItem(int _iId);
	~CItem();
};
