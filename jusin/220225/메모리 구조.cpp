#include <iostream>

using namespace std;
int iTemp = 1; // 전역변수: 한 파일 안에서는 전역적으로 사용이 가능한 변수 >> 데이터 영역에 할당


int main()
{

#pragma region 디버깅

	// 상단에 Debug, relese
	// Debug는 실행파일의 크기가 크고 속도도 크다. 하지만 코드 오류, 흐름을 점검할 수 있다.
	// relese는 가볍고 빠르다. 코드가 오류가 있으면 그냥 프로그램이 뻗는다.

	// Debug모드의 디버깅 기능
	// 그냥 F5를 누르면 디버깅으로 실행
	// 실행하면 디버그 포인트에 멈춘다
	// 멈춘상태에서 마우스를 호버링해 변수상태, 값 등을 확인할 수 있다
	
	// 구글에 디버깅 단축기치면 다른 기능들 많이 있음..

	// 프로그래밍 실력이 디버깅 실력이다 할 정도로 중요하다!!
	// 꾸준히 디버깅하는 습관 들여놓기!

#pragma endregion 



#pragma region 메모리

#pragma region data 영역과 stack 영역의 특성

	// 노트 필기

#pragma endregion


#pragma endregion

}


#pragma region 추가적인 함수 문법

// 디폴트 매개변수
// 선언이 있다면 몸체는 디폴트 표시 안 해야함
// 인자를 안넘겨주면 자동으로 100 전달
void Func(int a = 100)
{

}

// 뒤쪽 부터 디폴트 가능!!
void Func(int A, int B = 200)
{

}

// 사용 가능! 컴파일러는 얼마나 할당해줘만 관심!!
// 이름이 없으니 함수안에서 사용은 불가능!
void Print(int)
{

}



// 함수 오버로딩
// 함수의 이름이 같을 때 매개변수의 갯수, 자료형 타입에 따라 어떤 함수가 호출될 지 결정되는 문법
//  ㄴ 디폴트 매개변수를 활용하는 함수와 호출 모호성이 안 생기도록 주의!
// 전부 다른 함수이다!
void Draw()
{

}
void Draw(int a)
{
	
}
void Draw(float a)
{

}
void Draw(int a, int b)
{

}


namespace A
{
	void FuFunc()
	{

	}
}
namespace B
{
	void FuFunc()
	{

	}
}
using namespace A;
using A::FuFunc;
// A의 FuFunc를 사용한다는 말!


#pragma endregion 


#pragma region 재귀 함수

// 자기 자신에게 돌아가는 함수라는 뜻으로 자신을 다시 호출하는 형태의 함수이다

void Return()   // 스택 오버플로우!!
{
	cout << "재귀 호출" << endl;
	Return();
}
// 반드시 탈출 조건을 만들어 줘야한다!! >> 그래야 함수가 끝나서 스택 메모리를 반환하니깐
void Return(int iNumber)
{
	if (0 >= iNumber)
		return;
	cout << "재귀 호출" << endl;
	--iNumber;
	Return(iNumber);
}

#pragma endregion

// 숙제 5 팩토리얼을 재귀 함수로 구현해라
// 5*4*3*2*1 = 5!