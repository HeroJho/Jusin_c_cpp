#include "pch.h"

#pragma region friend

// friend 키워드 : 외부의 클래스의 private을 접근 허가하겠다.
// friend void Girl::SHowBoy(Boy& b)    >> 멤버 함수를 프렌드
// friend class CGirl;   Girl에서 Boy 클래스에서 선언된 private 멤버 변수 접근을 허용한다

// 유용한 문법이지만, 은닉화를 깨는 문법
// 진짜 필요할 경우 써라 (필살기)

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