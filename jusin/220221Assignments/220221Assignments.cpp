#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int main()
{
    int iKr = 0, iEn = 0, iMa = 0;
    int total = 0;
    float avg = 0.f;
    cout << "국어 점수를 입력하세요: ";
    cin >> iKr;
    cout << "영어 점수를 입력하세요: ";
    cin >> iEn;
    cout << "수학 점수를 입력하세요: ";
    cin >> iMa;

    total = iKr + iEn + iMa;
    avg = (float)total / 3;

    cout << "합계 점수: " << total << ", 평균: " << avg << endl;

    if (90 <= avg && 100 >= avg)
        cout << "A" << endl;
    else if (80 <= avg)
        cout << "B" << endl;
    else if (70 <= avg)
        cout << "C" << endl;
    else if (60 <= avg)
        cout << "D" << endl;
    else
        cout << "F" << endl;

    float avg = 0;
    cin >> avg;

    if (100 < avg)
    {
        cout << "잘못입력했씁다" << endl;
    }
    else
    {
        switch ((int)avg / 10)
        {
        case 10:
        case 9:
            cout << "A" << endl;
            break;
        case 8:
            cout << "B" << endl;
            break;
        case 7:
            cout << "C" << endl;
            break;
        case 6:
            cout << "D" << endl;
            break;
        default:
            cout << "F" << endl;
            break;
        }
    }
}
