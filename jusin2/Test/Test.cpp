#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include "pch.h"

using namespace std;

void Func(int&& a)
{
    a = 50;
    // cout << a << endl;
}

int main()
{
    int num1 = 20;

    // Rvalue 참조자 자료형은 Rvalue만 받을 수 있다.
    int&& num2 = num1;

    // std::move()함수를 통해 Lvalue를 Rvalue로 바꿀 수 있다.
    int&& num2 = std::move(num1);

    // 결국 참조자야.
    // Lvalue 참조자는 그냥 참조자 사용하면 된다.

// ===============================================================

    // 왜 Lvalue를 Rvalue로 바꿔서 Rvalue 참조자로 받아서 사용하냐.
    // 복사 생성자는 Lvalue 참조자를 받는다.
    // 그렇다면 복사 생성자와 이동 생성자를 구분할 방법이 없다.
    // 그래서 Lvalue 참조자와 Rvalue 참조자를 받는 생성자로 구별해서 구별한다.

  

    return 0;
}