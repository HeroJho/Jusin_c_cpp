#include "pch.h"

#pragma region this 포인터
// this 포인터
// 생성된 객체 자신의 주소값을 저장하고 있는 상수 포인터이다.

class CObj
{
private:
	int m_iA;
public:
	// 이 m_iA가 누구의 멤버 변수인지 알고?
	void Render(int _iA)
	{
		cout << m_iA << endl;
	}

	void AAA(CObj o)
	{
		*this = o;
	}


	void Render2(int _iA)
	{
		cout << this->m_iA << endl; // 클래스 내부는 this가 생략되어 있따
		// 그 객체의 주소를 가지고 있는 상수 포인터이다
	}
};

#pragma endregion



#pragma region exterm

// 전역 변수는 파일 내에서 쓸 수 있다
// 이 전연 변수를 다른 파일에서 쓰고 싶다
// 전역 변수 또는 전역 함수의 형태를 여러 파일 공간에서 공유하여 사용할 수 있게 된다.
// extern만 모아놓은 파일을 제작하는 것이 사용상 편리할 수 있따
// extern을 사용할 때 변수인 경우 자료형과 변수 이름이 동일해야 한다. 또 초기화할 수 없다.

// 외부에 존재한다는 것을 알리는 행위인 것이지 메모리를 할당하지 않는다. >> 그래서 초기화가 불가능하다

// exterm을 사용하기 보다는 차라리 클래스의 static을 사용해서 함수를 사용하는 것이 좋을 수도 있다

#pragma endregion 

void main()
{

}



// 상점 무기 방어구 구매 구현하기 상속 x