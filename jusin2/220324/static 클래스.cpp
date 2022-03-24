#include "pch.h"

#pragma region 멤버 변수

int A = 20;						// 정적변수(외부에서 접근 가능한 정적변수)

class CObj
{
public:
	// (영웅이네 사는) 해호  >> 어디에 속해있냐라고 명시해야함 
	static int m_iA;  // = 10;	// 생성과 동시에 초기화가 불가능! (이니셜도 마찬가지)
	int m_iB;
public:
	void Plus()
	{
		static int _iA = 10;	// 정적변수(내부에서 접근 가능한 정적변수)
		cout << m_iA++ << endl;
	}
};

// Obj.cpp
int CObj::m_iA = 100;	// 멤버로 존재하는 정적변수 초기화 문법 >> 초기화 안하면 Data의 Bss에서 자동으로 0


#pragma endregion

// 코드 영역 >> 함수, 자료형
// 데이터 영역 >>

#pragma region 멤버 함수

class CCObj
{
private:
	static int m_iA;
	int m_iB;
public:
	// static 멤버함수 안에서는 클래스 내의 일반 멤버 변수를 사용할 수 없다
	// 일반적인 멤버 함수 또한 호출이 불가능
	static void Render()
	{
		m_iA++;			// 같은 메모리 공간에서 생성되니 가능하다
		
		++m_iB;			// 메모리공간, 생성되는 타이밍 자체가 다르다, 어떤 객체의 m_iB인지 특정할 수 없다
		Draw();
	}

	void Draw()
	{
		// m_iB;
	}
};

#pragma endregion

// 1, static 멤버 함수는 static 멤버 변수와 동일한 기능을 가진다.
// 2. static으로 선언된 변수와 함수는 해당 클래스로 생성된 모든 객체가 공유한다.
// 3. 각 객체의 소유가 아니다
// 4. static 멤버 함수 내부에서는 일반적인 멤버 변수, 함수를 접근할 수 없다.
// 5. namespace를 통해 객체를 생성하지 않고 호출할 수 있다.
// 6. 프로그램 시작 시(컴파일 시점) 메모리가 할당되고 프로그램 종료 시 메모리가 해제된다.
// 7. 할당되는 메모리 공간은 data 영역에 해당한다.

void main()
{
	{
		CObj o0;   // > a는 데이터  b는 스택     

		CObj o1;
		o1.Plus();
		CObj o2;
		o2.Plus();
		CObj o3;
		o3.Plus();
		CObj o4;
		o4.Plus();
		CObj o5;
		o5.Plus();

		// static 변수도 접근제어 동일하게 적용
		// 이름으로 명시해서 접근할 수 있음
		CObj::m_iA = 10;

	}



	{
		CCObj::Render();
	}

}