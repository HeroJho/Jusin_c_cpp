#include <iostream>
using namespace std;

// 숙제 5 팩토리얼을 재귀 함수로 구현해라
// 5*4*3*2*1 = 5!

// 5번째 피보 = 4번째 피보 + 3번째 피보
// n번째 피보 = n-1번째 피보 + n-2번째 피보
int Fivo(int n)
{
    if (n <= 2)
        return 1;

    return Fivo(n - 1) + Fivo(n - 2);
}

static int n = 1;
void Func(int _n)
{
    if (0 >= _n)
    {
        cout << n << endl;
        n = 1;
        return;
    }
    n *= _n;
    --_n;
    Func(_n);
    
}


// 5번 팩 = 5 * 4번 팩
// n번 팩 = n * n-1번 팩
double Fact(int n)
{   
    if (0 == n)   // 0!는 1이다!
        return 1;
    else if (1 == n)
        return n;

    return n * Fact(n-1);
}

int main()
{
    cout << Fact(100) << endl;
}

