#include <iostream>

using namespace std;

void Rand()
{
	cout << 1 << endl;
}
int Get_A(int iA)
{
	return iA;
}
int Add(int iA, int iB)
{
	return iA + iB;
}
int Minus(int iA, int iB)
{
	return iA - iB;
}

void main()
{
#pragma region 함수 포인터

	// 함수 포인터 : 함수의 이름을 저장하기 위한 포인터
	// 함수의 이름 또한 함수가 등록된 메모리 영역(code)의 주소 값이 해당한다.
	// 함수 이름()   : () 함수호출 연산자
	cout << Rand << endl;  // 함수 이름 >> 이름을 가지고 주소값에 접근함 >> 하지만 코드 영역이라 변경이 불가능

	// 같은 함수 포인터를 가지고 재사용하는 형태로 여러 함수를 바꾸면서 사용하겠다는 것
	// c에서는 굉장히 좋은 문법이였지만 c++에서 클래스가 나오면서 탈락되어가는 문법이다.
	// 하지만 여전히 공부할 필요는 있다. >> c 구조체는 변수만 가능 > 함수넣을라면 함수 포인터 써야함 > c++은 클래스에 그냥 넣을 수 있음

	// 선언
	// 타입(*변수명)(매개변수) : 중간 공백이 있어도 상관없음
	void(*ptrVoid)(void) = Rand;
	ptrVoid();

	int(*ptrGet)(int) = Get_A;
	cout << ptrGet(10) << endl;

	int(*ptrAdd)(int, int) = Add;
	cout << Add << endl;

#pragma endregion


	// 함수 포인터 사용예
	{
		int(*ptrAdd)(int, int) = Add;
		cout << Add << endl;
	}
}

