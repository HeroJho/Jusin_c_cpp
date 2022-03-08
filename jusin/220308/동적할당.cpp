#include <iostream>

using namespace std;

char szName[16] = "";   // 파일 한계

char* Func()
{
	char szName[16] = "";     // 지역변수
	cin >> szName;

	return szName;
}

char* Func2()
{
	char* pName = (char*)calloc(16, sizeof(char));     // 지역변수
	cin >> pName;

	return pName;
}

void main()
{
	{
		char* pName = Func();   // 소멸, 쓰래기 값  >> 지역변수의 한계
		cout << pName << endl;
	}
	{
		char* pName = Func2();   // 임시 메모리 공간에 힙 주소를 저장
		cout << pName << endl;
	}

	// 런타임에 메모리를 할당하겠다 >> 동적 할당 (힙)
	{
		// 논리적으로 언제 할당하고 언제 해제할지 고민을 엄청 해야한다 >> 어렵다!!!
		
		// c언어 스타일 동적할당
		// malloc, calloc
		// void*	malloc(size_t size);   // 동적할당은 하지만 어떤 자료형인지는 알수 없다 void*
		// int* p = malloc(4);  // 힙공간에 4바이트 힙주소 반환
		// float인지 int형인지 알 수 없다.
		int* pp = (int*)malloc(4);
		// int* pp = (int*)malloc(sizeof(int));
		// void*: 어떤 주소값의 형태인지 알 수 없을 때 사용하는 문법. 선언 시점에는 void*해도 되지만 사용시점에는 어떤 자료형으로 형변환 필수!
		
		// 주소를 반환하기 때문에 포인터와 동적할당은 땔 수 없다!
		// 프로그램이 돌때 메모리를 할당하기 때문에 이름을 붙일 수 없기 때문에 포인터!
		*pp = 20;   // >> 20은 힙 pp는 스택
		cout << *pp << endl;  // >> 값 초기화 안하면 쓰래기값이 들어간다
		
		// 힙 영역은 문법적으로 메모리를 돌려줘야 한다!

		cout << pp << endl;
		// void free(void* p);
		free(pp);
		cout << pp << endl;
		// 메모리 공간을 다 썻다고 알리는 행동. 실질적으로 주소값을 삭제하지는 않음.

		// 댕글링 포인터   >> 최악의 실수!!!
		*pp = 100;
		cout << *pp << endl;    // 허가하지 않은 메모리 공간을 쓴 것
		// 메모리 해제 이후 nullptr로 초기화도 해주기!!
		pp = nullptr;
		// 절대 실수 ㄴㄴ 너무 당연히 null처리 해주는 거임


		// calloc
		// void*	calloc(size_t Count, size_t size)
		int* p = (int*)calloc(5, sizeof(int)); // 20바이트 할당

		for (int i = 0; i < 5; i++)
		{
			cout << p[i] << endl;       // 0으로 자동으로 초기화!
		}

		// 동적 배열을 만들고자 할 때 유용하다.
		int iCount = 0;
		cin >> iCount;
		int* pp = (int*)calloc(iCount, sizeof(int));

		// 하지만 동적 배열 malloc가능 >> 더욱 많이 사용 >> 인자가 하나니
		int* pp = (int*)malloc(iCount * sizeof(int)); // 단지 초기화가 자동으로 안되는 단점

		// c와 m의 차이
		// 인자값의 개수가 다르다
		// 할당한 힙 메모리 공간에 값을 c의 경우 자동 0초기화

	}


	// c++언어에서의 동적할당 >> 이거 사용해라
	{
		int* p = new int; // 연산자를 통해 동적할당 int형 크기만큼을 heap에 할당하고 첫 번째 주소를 return
		cout << p << endl;

		delete p;     // 연산자를 통해 메모리 해제
		// 댕글링 마찬가지로 존재
		p = nullptr;

		int* p2 = new int[4]; // int형 4개 크기만큼을 힙공간에 할당
		for (int i = 0; i < 4; i++)
		{
			// new는 m기반 >> 쓰래기값 초기화
			cout << p2[i] << endl;
		}

		// 동적배열 해제
		delete[] p2;
		// 댕글링
		p2 = nullptr;
	}

	// 조심해야할 사항 : 프로그래머는 heap메모리가 누수가 발생하지 않도록 반드시 관찰하고 메모리를 헤제하는 코드를 짜야한다!
	{
		// 힙 공간 포인터가 없다  >> 메모리 누수 >> 사용은 안하지만 할당되어있는 ...
		int iA = 100;
		int* p = new int;
		p = &iA;

		*p = 20;
	}


	// 코드의 성향을 포인터를 사용해라!! 동적할당을 적극적으로 사용해라!!
}

// 가장 즐거운 숙제
// 텍스트 알피지
// 직업 공격력 체력
// 사냥 종료
// 초급 .... 고급 선택
// 몬스터 능력치 달라짐
// 1전투 2도망
// 1 누르면 서로 공격
// 플레이어가 죽으면 체력 회복하고 복귀
