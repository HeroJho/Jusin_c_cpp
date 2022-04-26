#include "pch.h"

class Obj
{
private:
	int _a;
public:
	Obj()
	{

	}
	explicit Obj(int A)
	{
		_a = A;
	}
	~Obj()
	{

	}
};

int main()
{
	// 어디서 동적할당할지는 게임을 했을 때 언제 생성했엇지? 라는 경험에 비춰 해주면 된다

	Obj obj = 10;  // obj.=(10)   >> 디폴트 대입 연산자 함수 호출
				   // int형 인자를 하나 받는 생성자를 보고 비슷한 디폴트 대입 연산자를 만든다?

	obj = 10; //   << 값이 있다면 대입 연산자가 호출된다
	// ㄴ c++은 두가지 방법의 초기화를 허용한다.

	int a = 10;
	int aa(10);


	// 즉, 컴파일러가 묵시적으로 변환한 것은 위험한 것이다!
	// 묵시적 형변환을 원하지 않는다!
	// explicit

	{   // 둘 다 객체를 만들고 공간 할당   >> 10번의 생성자 호출
		Obj dddd[10];
		Obj* dd = new Obj[10];
	}

	return 0;
}