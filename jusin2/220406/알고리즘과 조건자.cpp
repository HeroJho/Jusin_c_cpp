#include "pch.h"

// 알고리즘 헤더 포함!
#include <algorithm>
// 알고리즘에 사용되는 제공되는 펑터 헤더!
#include <functional>


#pragma region 조건자

	// bool 타입을 반환하는 함수 또는 함수 객체(펑터).
	// stl 알고리즘을 수행하기 위한 조건을 제공하는 기능을 의미한다.
	
	// 보통 알고리즘 함수의 3번째 인자로 전달되어 특정 조건에 맞게 기능을 작동하게 된다.

#pragma endregion


#pragma region 왜 함수 포인터 대신 조건자를 사용하는가?

// 외부의 데이터를 생성자를 통해서 전달할 수 있다.
// 함수 포인터보다 함수 객체가 장점뿐 없다.

class CDeleteObj
{
private:
	int m_iA;

public:
	CDeleteObj(int iA)
		: m_iA(iA)
	{}

	template<typename T>
	void operator()(T& Temp)
	{
		if (Temp)
		{
			delete Temp;
			Temp = nullptr;
		}
	}
};

// 함수 포인터의 경우 5를 인자로 전달할 방법이 없음.
// for_each(vecInt.begin(), vecInt.end(), PrintPlusValue)   

// 객체라면 생성자를 통해 인자를 전달할 수 있다!
// for_each(vecInt.begin(), vecInt.end(), PrintPlusValue(5))   


#pragma endregion


#pragma region 자주 쓰이는 알고리즘 함수


#pragma region for_each()

// 컨테이너를 순회하는 알고리즘
// 3인자의 함수객체, 함수 포인터를 인자로 넣어서 원하는 작업을 순회한다

// for_each(vecInt.begin(), vecINt.end(), PrintValue<int>)

#pragma endregion

#pragma region sort()
	
	// 시퀀스 자료구조들을 정렬할 때 사용한다.
	// 오름차순 조건자 디폴트
	
	// sort(vecInt.begin(), vecInt.end(), Less<int>);

#pragma endregion

#pragma region count_if

	// 컨테이너 원소를 순회하면서 조건자의 반환 결과가 true일 때 개수를 반환하는 함수.
	// ex) 특정 범위에 있는 몬스터 마릿수.
	//     특정 상태가 있는 몬스터 마릿수.

	//int	iCount = count_if(vecInt.begin(), vecInt.end(), IsOddNum<int>);

#pragma endregion


#pragma endregion


#pragma region 결론

// for문을 사용하던 것들을 조건자만 따로 만들어서
// for_each를 사용하는 쪽으로 습관을 들이는게 좋은 코딩습관이다.

// for_each를 사용하는 것이 성능적인 면이나, 코드의 은닉성을 할 수 있다!

// 조건자를 만들어서 알고리즘 함수 사용법에 익숙해 질 것!!

#pragma endregion

