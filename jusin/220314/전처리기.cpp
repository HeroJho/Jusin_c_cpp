#pragma region 전처리기

// 심볼릭 상수는 코드에서 문제가 나온다  >> 컴파일 타이밍에 이뤄짐 > 자료형도 있다
// 매크로는 리터널 상수     >>   컴파일전에서 

#include <iostream>

// 강제 치환 : 컴파일 타임 이전에 해당 매크로 위치에 값이 그대로 치환된다.
// 컴파일전 실행 >> 세미클론은 컴파일 단계에서 줄 끝을 알리는 것 >> 전처리기 뒤에 붙이지는 않는다.

// 매크로라고도 부른다

// 상수 매크로
#define		PI		3.14f

// 함수 매크로
// #define		SQUARE(x)	x*x
#define		SQUARE(x)	((x)*(x))
// 자료형과 상관없이 그대로 치환된다.
// 함수는 아니다! 주소가 없다 >> 코드가 이식되는 것이다
// 연산자 우선순위를 생각해서 소괄호를 신경 써야한다.

// 역슬러쉬를 삽입하여 1줄 띄어쓰기가 가능하다. 
#define		SQUARE(x)\
			((x)*(x))

// 컴파일 전에 실행되기 때문에 속도가 빠르다
// 한 줄짜리 코드를 만들 때 주로 사용한다(간단한 함수를 자주 사용할 때 만든다)

// 단점: 
// 전처리기이다보니 디버깅에 어려움이 있다.
// 복잡한 함수를 구현하기 어렵다.

// 함수 매크로를 이용한 문자열 치환
#define		STRINGTEMP(A, B)	A"의 직업은"B"입니다"


#pragma endregion

#pragma region 조건부 컴파일

#if(조건) : if문의 시작과 동일한 기능
#endif(조건) : elseif
#else
#endif : 조건부 컴파일 종료

#ifdef   정의 되었다면
#endif : 조건부 컴파일 종료

#ifndef   정의 안 됐다면
#endif : 조건부 컴파일 종료

#define 

#pragma endregion

using namespace std;

int main()
{
	cout << PI << endl;   // ==  cout << 3.14 << endl;   
}



// 컴파일 타임 이전에 작업을 수행하는 것



