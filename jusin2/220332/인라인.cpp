#include "pch.h"

// 일반화 프로그래밍
//  ㄴ데이터 형식에 의존하지 않고, 하나의 값이 여러 다른 데이터 타입들을 가질 수 있는 기술에 중점을 두어 재사용성을 높일 수 있는 프로그래밍 방식
// 매크로도 일반화 프로그래밍 >> 자료구조에 의존x 재사용o
// c++ 되면서 매크로에서 추가된 것
// 인라인 함수, 연산자 오버로딩, 템플릿이 추가 됐다


#pragma region 인라인

#pragma region 예제 코드

#define			SQUARE(x) x * x

// 앞에 inline이 생략되어 있음
inline int		Square(int iX)
{
	return iX * iX;
}

#pragma endregion

#pragma region 정의
// 정의
	// 컴파일 시점에 함수 호출위치에 바로 함수 코드를 삽입하는 형태의 함수
	// 매크로와 다른점은 자료형에 의존적이다.
#pragma endregion

#pragma region 성능
// 성능
	//	매크로는 단순 치환의 기능을 갖고 있다. (호출의 개념이 아니다)
	//    ㄴ함수보다 월등히 빠르다
#pragma endregion

#pragma region 왜 인라인을 사용하냐?
// 왜 매크로말고 인라인 함수를 쓰냐?
	// 프로그래머는 코드를 유지보수가 좋게 코드 짜는게 중요하다
	// 매크로는 이 부분에서 좋지 않다. 
	//	ㄴ디버깅 불편(눈으로 해야한다)
	//  ㄴ작성이 불편(줄 띄우기)
#pragma endregion

#pragma region 인라인 조건
// 인라인 조건
	// 선언과 동시에 몸체까지 구현돼야 인라인으로 인식한다
	//   ㄴ헤더와 멤버변수정의를 분리하면 인라인이 아니다!
	// Get과 Set같은 8줄 이하의 짧은 함수는 헤더에 몸체도 구현해서 인라인의 장점을 가져간다
	//   ㄴ꼭 8줄 이하라고 인라인 하는 것은 아니다. 어쨋든 컴파일에서 결정한다.
#pragma endregion

#pragma region 인라인이 일반 함수로 바뀌는 경우

	// 1. void(*ptr)() = Func , 인라인 함수를 함수 포인터로 활용할 때, 주소가 필요하니 함수로 만들어서 넣는다
	// 2. 인라인 함수를 재귀 형태로 호출할 때  >> 함수를 또 호출해야하니 메모리에 등록해서 사용 >> 몇번 치환을 해야해? 문제도 있다
	// - 그 외에 컴파일이 알아서 한다. 

#pragma endregion

#pragma region 결론

// 컴파일러가 발전하면서 현시대는 inline을 붙여주는게 무의미
// 컴파일러가 판단해서 inline을 자동으로 한다.
// 프로그래머가 inline을 신경쓰면서 코딩할 필요는 없다.

#pragma endregion

int main()
{
	cout << SQUARE(10) << endl;

	cout << Square(20) << endl;

	return 0;
}

#pragma endregion