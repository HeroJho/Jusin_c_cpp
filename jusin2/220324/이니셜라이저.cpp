#include "pch.h"

#pragma region 이니셜라이저
// 이니셜라이저
// 생성자에서 상수를 초기화하기 위한 문법
// 생성과 동시에 초기화하는 문법
class CObj
{
private:
	const int		m_iA;

public:


public:
	// 컴파일러가 헤더를 읽을 때 이니셜라이저를 읽는다
	// 그래서 선언과 동시에 초기화하기 때문에 일반 변수들도 초기화할 때 많이 사용한다 >> 대입 연산보다 빠르다
	// 배열이나 구조체를 한 번에 초기화할 때는 이니셜라이저가 불가능하다.
	CObj() : m_iA(10)
	{ 
		// m_iA는 생성자가 호출돼서 쓰래기값
		// m_iA = 10;	대입을 통한 초기화 
	}
};

#pragma endregion


void main()
{

}