#include <iostream>
using namespace std;

int main()
{
    // 메모리 함수: 메모리 대 메모리 단위로 데이터들을 초기화 또는 복사하는 함수
    //   ㄴ이런 메모리 함수는 되게 많다! 필요할 때마다 찾아보기!

    // void* memset(void* pDest, int Value, size_t Size); : 메모리 초기화 함수
    //  1인자: 초기화하고자하는 데이터 주소,  2인자: 바이트 단위로 초기화할 값, 3인자: 얼마만큼의 크기 초기화할 건지
    {
        int Array[5];
        memset(Array, 0, sizeof(Array));
    }
    { // 2번째 인자의 중요성
        int iA = 0;
        memset(&iA, 1, sizeof(int));
        cout << iA << endl;      // 이상한 값! >> 바이트 단위로 초기화 하니깐
        // int는 4바이트, 2번째 인자 바이트 단위로 초기화. >> 4바이트 각각 1로 초기화
        
        // 그래서 배열이나 구조체를 초기화할 때만 사용한다.
        // 대부분 memset은 0으로 초기화하는 용도로 사용한다!
    }

    // void* memcpy(void* pDest, const void* pSrc, size_t Size) : 메모리 복사 함수
    // 1인자 : 복사 받을 변수의 시작 주소,   2인자: 복사를 수행할 원본 변수의 주소,   3인자: 복사할 메모리 크기
    {
        int iSrc[5] = { 1,2,3,4,5 };
        int iDest[5] = {};

        // 5번의 대입 발생!   >> 이런 배열 복사는 비효율적..
        for (int i = 0; i < 5; i++)
        {
            iDest[i] = iSrc[i];
        }

        memcpy(iDest, iSrc, sizeof(iSrc)); // 1번의 함수 호출로 복사 끝!
    }

    // memmove : memcpy 과 같지만 내부적이 동작이 좀 다르다.
    {
        // 복사를 하기전에 임시적인 메모리 공간을 만들고, 임시 메모리의 데이터를 복사한다.
        // 당연히 memcpy가 빠르다!

        // memmove를 왜 써?
        // memcpy의 경우 linux 운영체제에서 사용 불가, memmove의 경우 윈도우 리눅스 모두 사용 가능.
    }


}
