#include "pch.h"

#pragma region 클래스 안에서 존재하는 함수의 상수화

// const >> 읽기 전용으로 사용하겠다는 말이다

class COBj
{
private:
	const int m_iA = 10;
public:
	// 읽기전용 함수
	void Render() const
	{
		// m_iA = 20;     // 쓰기 기능을 수행할 수 없다
		cout << m_iA;

		Draw();    // 컴파일 단계에서는 정의를 알 수 없다. >> 데이터의 변경 가능성이 열려있다는 말이다.
		DrawC();	// 너도 읽기 전용이구나? ㅇㅋ 허락한다
	}

	void Draw()
	{
		cout << "Hi" << endl;
	}

	void DrawC() const
	{
		cout << "Hi" << endl;
	}

	// const의 여부 또한 오버로딩의 조건이다
	// const가 붙은 객체가 호출하면 const함수를 호출한다
	void Draw() const
	{
		cout << "constDraw" << endl;
	}

public:
	// const + 참조자  : 메모리 복사 방지 >> 변경 금지

	const int& Get_A()  // 그냥 int로 반환하면 임시메모리 발생 >> 참조자 사용 >> const를 반환하니 참조자도 const사용
	{
		return m_iA;
	}

	const int& Get_A() const // 왠만한 get함수는 이런식으로 설계를해도 무관하다
	{
		return m_iA;
	}

	void Set_A(const int& _iA)
	{
		m_iA = _iA;     // 매개변수로 상수를 받아서 값 변경을 하지 않는 경우
		_iA = 10;		// 메모리 복사가 발생할 일이 없다, const를 붙여서 값 변경이 없다
	}
};

// 일반적인 재귀함수의 경우는 const를 붙여서 인자가 읽기 전용으로 해버리면 안된다.
// 멈출 수 있는 조건이 없어진다.   >> 는 아니고... 그냥 지양하자

// 선언부와 정의부로 나눴다면
// 몸체에도 똑같이 const를 붙여줘야 한다

#pragma endregion

void main()
{
	COBj co;
	cout << co.Get_A();
}