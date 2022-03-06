#include <iostream>
using namespace std;

// call by value  : 함수를 호출할 때 인자가 값 복사가 일어난 것
// call by reference: 함수를 호출할 때 주솟 값을 통해 작업을 하는 것
//    ㄴ 주솟값 역시 복사하는 것이지만, 주솟 값으로 접근 한다는 행위가 reference

int main()
{
#pragma region 이중 포인터

	// 이중포인터든 삼중포인터든 똑같은 포인터이다.

	int* p = nullptr;
	int** pp = &p;          // int포인터형 주소를 저장하는 포인터
	cout << sizeof(pp) << endl;

	{
		int itemp = 10;
		int* p = &itemp;
		int** pp = &p;

		cout << "itemp 주소 값 : " << (&itemp) << endl;
		cout << "p 주소 값 : " << (&p) << endl;
		cout << "pp 주소 값 : " << (&pp) << endl;
		
		cout << "itemp 값 : " << itemp << endl;
		cout << "p 값 : " << *p << endl;
		cout << "pp 값 : " << *pp << endl;

		cout << "pp가 가리키는 주소의 값" << **pp << endl;
	}

#pragma endregion


#pragma region 포인터의 형 변환
	{
		// 포인터의 캐스트
		int iA = 10;
		int* p = &iA;

		// 포인터는 자료형 타입만 일치한다면 주소 값을 저장하는 용도 자체는 가능하다.
		float* fp = (float*)p;

		*fp = 20.f;    // 대입할 때 실수공간처럼 대입함
		               // 하지만 실제로는 int형 램 공간
		               // 심각한 문제가 발생한다.

		cout << iA << endl;
		// 이런 기본 자료형 포인터는 캐스트할 일은 없다
		// 향후에 사용자 정의 자료형을 배울 때 많이 사용이 된다.

	}

#pragma endregion


#pragma region const와 포인터의 관계

	// const
	{
		// const : 읽기 전용으로 사용하겠다
		// const int iA;  쓰래기 값을 상수를 쓰겠다는 건데 허용하지 않는다.
		// 즉, const는 선언과 동시에 초기화를 해줘야 한다!
	}

	// const와 포인터
	{
		int iA = 0;

		// 포인터가 가리키는 공간을 상수화 하는 것
		// 외부의 데이터를 출력하는 용도로만 사용하고 싶을 때
		const int* pA = &iA; 
		// *pA = 20 에러!

		int* const p = &iA; // 주소값을 A의 주소로 상수화 시키겠다!
		// 오로지 하나의 메모리 공간만 참조하는 포인터

		const int* const ppp = &iA; // 주소가 가리키는 공간, 주소도 변경이 불가능하다


	}


#pragma endregion

}


