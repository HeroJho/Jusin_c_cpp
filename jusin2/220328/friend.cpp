#include "pch.h"

#pragma region friend

// friend Ű���� : �ܺ��� Ŭ������ private�� ���� �㰡�ϰڴ�.
// friend void Girl::SHowBoy(Boy& b)    >> ��� �Լ��� ������
// friend class CGirl;   Girl���� Boy Ŭ�������� ����� private ��� ���� ������ ����Ѵ�

// ������ ����������, ����ȭ�� ���� ����
// ��¥ �ʿ��� ��� ��� (�ʻ��)

#pragma endregion

class Girl
{
private:
	int m_iA;

	friend class Boy;
public:
	void PrintBoy()
	{
		Girl g;
		g.m_iA;
	}

};

class Boy
{
private:
	int m_iA;

public:
	void PrintGirl(Girl& _cG)
	{
		cout << _cG.m_iA << endl;
	}

	friend void Girl::PrintBoy();

};