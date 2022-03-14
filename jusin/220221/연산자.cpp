#include <iostream>
#include <bitset>
using namespace std;

int main()
{

#pragma region 시프트 연산자

    // 각 비트를 왼쪽, 오른쪽으로 이동시키는 연산자
    int itemp = 10;

    cout << bitset<8>(itemp) << endl;
    // 오른쪽 시프트시 맨 왼쪽 비트가 뭔지에 따라 새로 생기는 비트가 달라진다.
    cout << bitset<8>(itemp >> 2) << endl; // 2^2을 나눈다
    cout << bitset<8>(itemp << 2) << endl; // 2^2을 곱한다
    // 컴퓨터는 비트 연산을 좋아하기 때문에 위 처럼 나누고 곱하기도 한다.
    // 왼쪽 시프트 연산시 오버플로우를 유의해야 한다.
    // 오른쪽은 탈락 되기 때문에 별로 유의할게 없다.

#pragma endregion


#pragma region 증감 연산자

    // ++, -- : 하나를 증가 또는 감소 시키는 연산자
    int iNumber = 10;
    ++iNumber;
    cout << iNumber << endl;

    // 1.상수는 증감 연산자를 사용할 수 없다.
    // 2.증감 연산자가 붙어있는 위치에 따라 기능이 달라진다.
    ++iNumber;  // 전위 연산 : 선 연산 후 대입
    iNumber++;  // 후위 연산 : 선 대입 후 연산
    // 전위 연산이 후위 연산보다 빠르기 때문에 전위 연산을 자주 사용한다.
    // 3.연달아 사용이 가능하다.
    iNumber = 3;
    cout << ++(++iNumber) << endl;
    // (iNumber++)++ 는 에러난다!
    // 대입 후 연산인데 구분이 안간다!
    // 후위 연산이 나온 시점부터 연달아서 못한다!

#pragma endregion


#pragma region 연산자 축약

    int iNumber = 10;
    iNumber = iNumber + 1;
    iNumber += 1; // 둘은 같다! 산술 연산자는 모두 가능하다.

#pragma endregion


#pragma region 삼항 연산자

    // 간단한 조건을 이용하여 값을 도출하고자 할 때 사용한다.
    int iNum1 = 10;
    int iNum2 = 20;
    int iResult = 0;

    // 결과 = 조건 ? 참일 경우 반환 : 거짓일 경우 반환
    iResult = (iNum1 > iNum2) ? iNum1 : iNum2;

#pragma endregion


#pragma region 형 변환

    // 사용자가 프로그램 코드 진행에 따라 원하는 자료형으로 강제적으로 변환하는 것
    int iNum1 = 1;
    float avg = 0;
    avg = iNum1 / 3.f; // iNum1을 float을 묵시적으로 형변환 된다
    // 묵시적 형변환은 개발자라면 사용 x
    // 명시적 형변환을 되도록 사용해야 한다! 
    avg = (float)iNum1;
    // 형변환은 컴퓨터 입장에서는 부담이 되는 작업! >> 어쩔 수 없을 때 사용하기!

#pragma endregion

}
