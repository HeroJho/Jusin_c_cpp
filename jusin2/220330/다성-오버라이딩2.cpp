﻿#include "pch.h"


int main()
{
	// 문제: 
	// 같은 자료형으로 통일되게 유지보수 하고 싶다.  >> 상속의 목적
	// 자료형은 부모 자료형을 쓰지만 실질적인 객체의 형태는 자식으로 쓰고 싶다 >> 오버라이딩
	// 오버라이딩 하려고보니, 부모에 몸체가 빈 쓸대없는 함수가 너무 많아진다
	// 자식이 동적할당 될 때 부모의 모든 함수를 가지고 만들어진다!!! >> 낭비

#pragma region 순수 가상함수 & 추상 클래스
	
	// virtual Func() = 0; 
	// 위와 같이 순수 가상함수(오버라이딩을 위해 가상함수)를 만들 수 있다. (몸체 정의 x)
	// 순수 가상함수가 하나라도 있는 클래스를 '추상 클래스'라고 한다.

	// 추상 클래스의 특징
	// 1.추상 클래스는 객체 생성이 불가능하다.
	//		ㄴ컴파일러에서 이런 멤버함수가 있다는 것을 알려만 준다
	//			ㄴ객체 생성을 할 때 함수 몸체가 없으므로 생성 불가능
	// 2.자식에서 부모의 순수 가상함수를 무조건 구연해 줘야한다.
	//		ㄴ컴파일러와 일종의 약속이다. 'Render라는 멤버함수가 있는데, 자식에서 만들어 줄거야'

#pragma endregion

	// 생각 정리
	// 어쨋든 순수 가상함수, 추상 클래스를 만들면 부모 클래스에 함수들이 몰리는 문제를 해결할 수 없다.
	// 오히려 순수 가상함수를 사용함으로서 자식들에 필요없는 멤버함수를 구현을 해야한다!
	// 순수 가상함수, 추상 클래스를 만듦으로서 해당 부모 클래스를 유지보수용으로 사용하 겠다는 것과,
	// 자식들이 꼭 해당 함수를 가지고 있게끔 해줄 수 있는 문법인 것 같다.


#pragma region 가상 소멸자

	// 가상 소멸자  *중요!!
	// 자식의 포인터로 delete하면 '자식 > 부모 > 메모리 해제' 순으로 호출.
	// 문제 : 
	//		부모 '포인터'로 delete하면 부모의 소멸자만 호출되어 자식에서 메모리 누수가 발생한다
	//		delete는 포인터의 자료형, 주소을 근거로 소멸자를 호출하고 메모리 할당을 해제한다.
	// 해결: 
	//		부모의 소멸자에 virtual해서 자식의 소멸자를 부른다.
	//		자식의 소멸자가 호출되니깐 부모의 소멸자는 내부적으로 자동으로 호출된다.
	// 결론:
	//		만약 상속을 했다면(부모 클래스의 가상함수가 있다면) 
	//		부모 클래스의 소멸자에는 virtual키워드를 반드시 붙여라!!!!!

#pragma endregion


#pragma region 명시 키워드

	// 써도 그만 키워드 (표시용)
	// abstract : 추상 클래스 명시
	// override : 오버라이딩한 함수 명시
	// final : 마지막 자식 객체 명시

#pragma endregion 

}

