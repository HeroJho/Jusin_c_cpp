#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#pragma region 람다 표현식이란?

// -함수 객체 때문에 발생한 문법
//		ㄴ함수 객체의 단점 : 작성에 용이하지 못하다.
//		ㄴ일반 사용 시점에서 함수인지 객체인지 구분이 어렵다.

// -이름 없는 "무명 함수"이다.

// -람다식의 장점
//		ㄴ작성이 편리하고, 가독성이 증가된다. 
//		ㄴ작동 속도가 빠르다.
//			ㄴ람다식은 인라인 함수이다 > 그 즉시 호출되고 사라진다 > 메모리에 올라갈 일이 없다.
//		ㄴ함수 선언부나 몸체를 따로 찾을 필요가 없기 때문에 가독성이 증가된다.
//			ㄴ함수 선언부나 몸체를 따로 찾을 필요가 없기 때문에 가독성이 증가된다.


// -람다식의 단점
//		ㄴ코드를 숨기는 식이라면 람다식은 그 부분에서 좋지 않다.

#pragma endregion


#pragma region 람다 문법


#pragma region 사용 예제

void main()
{
	// 모든 원소 순회 출력
	vector<int>		vec{ 10, 20, 33, 40, 50 };

	for_each(vec.begin(), vec.end(), [](int n) {cout << n << endl; });


	// 홀수 원소 찾기
	auto		iter = find_if(vec.begin(),
		vec.end(),
		[](int n)->bool { return (0 != n % 2);  });

	cout << (*iter) << endl;


	// 원소 홀짝 더하기
	vector<int>		vec{ 1, 2, 3, 4, 5 };

	int	iEvenSum = 0;
	int	iOddSum = 0;

	for_each(vec.begin(), vec.end(), [&](int n) {
		if (0 == n % 2)
			iEvenSum += n;
		else
			iOddSum += n;
		});

	cout << iEvenSum << endl;
	cout << iOddSum << endl;

}


#pragma endregion


#pragma region 기본 문법

// [] : '람다 소개자', 컴파일러가 이 기호를 만나면 람다식으로 인지하게 됨
// () : '파라미터 지정자', 일반 함수의 파라미터와 동일함
// {} : '람다 몸체',  일반 함수의 몸체와 같은 의미

void main()
{
	// 람다식을 만들고 함수 호출 연산자 "()"를 붙이면 사용할 수 있다.
	[]() {cout << "hello world" << endl; }();
	[](int iTemp) { cout << iTemp << endl; }(100);
	[](int iTemp = 100) { cout << iTemp << endl; }();
}

#pragma endregion


#pragma region 묵시적 반환과 명시적 반환

void main()
{
	// 묵시적 반환 : 람다 함수 몸체 내부에서 발생한 결과값으로 컴파일러가 추론하여 반환 타입을 결정
	int	iResult = [](int iTemp, int iSour) { return iTemp + iSour;  }(10, 20);

	// 명시적 반환
	int	iResult = [](int iTemp, int iSour)->int { return iTemp + iSour;  }(10, 20);
}

#pragma endregion


#pragma region 캡처절

// -람다 소개자를 다르게 부르는 표현.
// -외부에 있는 데이터를 참조하는 방식을 기호화한 것.

void main()
{
	vector<int>		vec{ 1, 2, 3, 4, 5 };

	int	iEvenSum = 0;
	int	iOddSum = 0;

	// 값으로 복사하여 캡처(복사 값은 const 성향이 되어 읽기 전용이 된다.)
	for_each(vec.begin(), vec.end(),
		[iEvenSum, iOddSum](int n)	mutable	
		{
			if (0 == n % 2)
				iEvenSum += n;	// 사본

			else
				iOddSum += n;	// 사본

		});

	cout << iEvenSum << endl;		// 원본 변경이 일어나지 않음
	cout << iOddSum << endl;		// 원본 변경이 일어나지 않음



	// 레퍼런스로 캡처
	int	a = 10, b = 20, c = 30, d = 40;

 	[&a, &b, &c](int n)			
 	{
 		a += n;
 		b += n;
 		c += n;
 		d += n;

 	}(100);

 	cout << a << endl;
 	cout << b << endl;
 	cout << c << endl;
 	cout << d << endl;
}

#pragma endregion


#pragma endregion
