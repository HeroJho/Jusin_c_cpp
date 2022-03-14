#include <iostream>

using namespace std;

#pragma region typedef
// typedef int STAET; // 기존에 존재하는 자료형 이름과 더불어 사용자가 원하는 이름을 붙이는 것
// api에서 기본적으로 사용하는 것들
typedef int BOOL;
typedef unsigned long DWORD;
typedef unsigned short WORD;
#pragma endregion

#pragma region 구조체 + typedef
typedef struct tagInfos
{

};

typedef struct tagInfos
{

}INFO, *PINFO; // 포인터 타입 구조

struct tagInfo
{

};


// struct에 멤버 함수를 넣어서 class처럼 사용X 나쁜 습관!! 클래스를 써라!  (둘은 완전 똑같음)
struct ttagInfo
{
    int iA;       // 멤버 변수

    void Render() // 멤버 함수   (c++에서 허용하는 문법으로 c는 선언조차 할 수 없다)
    {
        cout << iA << endl;
    }
};
#pragma endregion

#pragma region 공용체

union uniTemp
{
    short a;
    int b;
    long long c;

    float d;  // 실수타입이 있따면?
};

#pragma endregion

#pragma region 열거체

// 상수를 만드는 문법
enum NUMBER
{
    ONE = 1,
    TWO = 110,
    THREE // 111    정의하지 않은 것은 앞의 상수 다음 숫자를 따라온다
};

#pragma endregion

int main()
{
#pragma region typedef

    struct tagInfo tInfo; // c시절에 구조체 변수 선언 방식
    tagInfo tInfo;   // c++에서 허용하게 된 구조체 변수

    tagInfo* pInfos;
    INFO info;
    PINFO pInfo;

#pragma endregion

#pragma region 공용체
    // 공용체
    {
        // 공용체는 연속된 메모리 공간을 사용하는 자료형이 아니라 가장 큰 메모리 블록크기 만큼만 할당하고 공유하는 문법

        //uniTemp uTemp = {10, 20, 30};  // 메모리 공간은 하나인데 초기화가 3개라서
        {
            uniTemp uTemp = { 10 };
            cout << sizeof(uTemp) << endl; // 가장큰 메모리공간만 할당 (블록단위)
            cout << uTemp.a << endl;
            cout << uTemp.b << endl;
            cout << uTemp.c << endl;

            uTemp.c = 200;

            cout << uTemp.a << endl;    // 결국 메모리 공간이 하나!
            cout << uTemp.b << endl;
            cout << uTemp.c << endl;
        }

        {
            // d를 출력할 땐 이상한 값이 나온다.
            // 즉, 너무 다른 자료형을 하면 안된다!

        }
        
        // 왜 union문법이 있냐?

        // 현재는 메모리가 풍부해서 잘 안 쓴다.
        // 오락실 게임 >> 전용 운영체제,  PC >> 윈도우 운영체제(다양한 하드웨어랑 호환)
        // 전용 운영체제를 쓴다면(메모리 공간 중요) 그 프로그램만 돌아갈 만큼 RAM용량만 있으면 된다.
        
        // 메모리 단편화
        // 내부, 외부 단편화
        // 외부 단편화 >> 구조체가 그럴 수 있다
        // 외부 단편화 문제를 공용체를 써서 필요한 만큼만 할당해서 쓰자  >> 임베디드에 필수!

        // 옛날에는 longlong같이 큰 자료형이 없었다.
        // 8바이트 짜리 변수 만드는법
        struct tagInfoaaa
        {
            int iA;
            int iB;
        };
        union uniDest
        {
            tagInfo t;
        };
    }
#pragma endregion

#pragma region 열거체
    // 열거체
    {
        cout << ONE << endl;
        cout << TWO << endl;
        cout << THREE << endl;

        // 왜 사용하냐?
        // 가독성을 높이기 때문에!!
        // 엄청나게 사용하게 된다
        NUMBER eType = ONE;

        cout << eType << endl;
        eType = THREE;
        cout << eType << endl;
        // 상수니 불가능 eType--;

        // 열거체의 크기는?
        cout << sizeof(NUMBER) << endl; // 갯수와 상관없이 무조건 4바이트 >> 상수 값을 저장하는 방식 >> 상수는 4바이트
        // 실수는 불가능!!

        cout << NUMBER(THREE) << endl;
        for (int i = 0; i < 3; i++)
        {
            cout << NUMBER(i) << endl;
        }
    }
#pragma endregion

}
