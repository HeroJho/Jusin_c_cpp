#include <iostream>
using namespace std;

int main()
{
    int korean = 0;
    int english = 0;
    int maths = 0;
    double total = 0;
    double avg = 0;

    // 한 줄에 선언과 동시에 초기화 가능
    //int korean = 0, english = 0, maths = 0;

    cout << "국어 점수를 입력하세요: ";
    cin >> korean;
    cout << "영어 점수를 입력하세요: ";
    cin >> english;
    cout << "수학 점수를 입력하세요: ";
    cin >> maths;

    total = korean + english + maths;
    avg = total / 3;

    cout << "-------점수-------" << endl;
    cout << "국어: " << korean << endl;
    cout << "영어: " << english << endl;
    cout << "수학: " << maths << endl;
    cout << "총점: " << total << endl;
    cout << "평균: " << avg << endl;
}
