#include <iostream>
using namespace std;

// 버블정렬은 최악 알고리즘 지수!
// 하지만 구현하기 간단해서 면접에서 손코딩하라고 많이 함
// 그래서 구현할 줄 알아야 한다.

int main()
{
    // 배열 포인터 : 배열의 주소값을 저장하는 포인터
    int iArray[] = { 1, 2, 3 };
    int* p = iArray;

    // 배열의 이름은 상수 포인터 인가?

    // 포인터 배열 : 포인터를 여러개 선언할 때 사용하는 문법
    int iA, iB, iC;
    int* pArray[3] = { &iA, &iB, &iC };

#pragma region 2차원 배열

    // 노트 필기 2차원 배열의 메모리 구조
    {    
                //행 열
        int iArray[2][3] = 
        {
            {1, 2, 3},
            {4, 5, 6}
        };
        cout << iArray[1][1] << endl;
        cout << (*(iArray + 1))[1] << endl;
        cout << *(iArray[1] + 1) << endl;
        cout << *((*(iArray + 1)) + 1) << endl;
        // 소가로의 안쪽부터 천천히 읽어가면 된다!

        //int** p = iArray;  // 2차원 배열의 이름은 2중 포인터 x,

        // 2차원 배열의 포인터형
        // 자료형 (*변수명) [열]
        int(*pArray)[3] = iArray;
        cout << pArray[1][1] << endl;

        int* p = iArray[0];
        cout << p[1] << endl;


    }

#pragma endregion
}

// 1. 2차원 배열을 이용하여 90도 시계방향으로 4회전하여 출력하기

// 2. 빙고 게임 (2차원 배열 안해도 되고 맘대로)  // 빙고판 두개 띄워서 번갈아 가면서 AI와 대결 구현해 보기
// 5 * 5 배열을 이용하여 1-25 숫자를 랜덤하게 출력
// 숫자를 선택해서 입력하면 일치하는 숫자는 *로 출력
// *로 표시된 숫자가 가로, 세로 대각선으로 5개가 될때마다 빙고가 하나 증가
// 5빙고가 되면 승리로 종료
