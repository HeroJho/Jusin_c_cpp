#include <iostream>
using namespace std;

// 키워드-자료형의 이름
struct tagInfo   
{
	bool bChoice;
	char szName[64];	// 
	int iA;				// 12/16
	float fB;			// 16/12
	double dbTemp;		// 8
};
struct Player
{
	char D[26];	// 48/46
	int hp;		// 24/20
	float A;	// 16/16
	float B;	// 16/12
	double C;	// 8/8
};

struct tegTemp
{
	char cName;
	short sBB;
	int iAA;
	long long llCC;

	tagInfo tInfo;	// 사용자 정의 자료형은 구조체 메모리 할당 정책을 따르지 않는다.
};

void main()
{
	// 구조체 : 여러 자료형을 한데 묶어서 관리하는 사용자 정의 자료형
	// 사용자 정의 자료형: 사용자가 직접 자료형을 만들어 사용한다는 것, 기본 자료형을 조합해서
	//    ㄴ 구조체, 열거체, 공용체
	//    ㄴ c++은 클래스 추가

	{
		// 구조체 선언
		tagInfo tInfo;

		cout << "이름 입력 : ";
		cin >> tInfo.szName;		// . 멤버접근 연산자

		cout << "int형 변수 입력: ";
		cin >> tInfo.iA;

		cout << tInfo.szName << endl;
		cout << tInfo.iA << endl;
	}

	{
		// 구조체 초기화
		// 멤버 변수가 선언된 순서로 초기화
		tagInfo tInfo = { "홍길동", 100, 6.27 };
		tagInfo tInfo2 = {  };
		cout << tInfo.szName << endl;
	}

	{
		// 구조체 크기
		// 메모리할당할 때 멤버 자료형중 가장 큰 자료형을 기준으로 메모리 블럭을 잡는다.
		// 메모리 블럭에 멤버 공간을 할당하고 부족하면 메모리 블럭만큼 또 할당.
		// 메모리 블럭은 기본자료형만 해당된다.
		tagInfo tInfo = {};
		cout << sizeof(tagInfo);
	}

	{
		// 구조체도 포인터 가능! 똑같이 4바이트
		tagInfo tInfo = {};
		tagInfo* ptInfo = &tInfo;
		
		(*ptInfo).fB;
		ptInfo->fB;
	}
}

// 숙제: 성적 프로그램 구조체 사용해서 만들기