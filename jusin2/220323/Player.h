#pragma once

//#include "Monster.h"

class CMonster;		// 전방 선언(자료형의 유무 판단만 할뿐 클래스 내의 변수와 함수에 대한 정보는 전혀 알 수가 없다)

// 1. 전방 선언 이후, 객체 타입은 멤버 변수로 선언이 불가하여 반드시 포인터 타입으로 선언해야 한다.
// 2. cpp파일에 헤더파일을 받드시 포함하여 자료형 또는 함수의 호출 권한을 부여할 수 있게 해야 한다.

class CPlayer
{
private:
	int			m_iA;
	CMonster* m_pMonster;

public:
	void		Render() { cout << m_iA << endl; }
	void		Draw(void);

public:
	CPlayer();
	~CPlayer();
};

