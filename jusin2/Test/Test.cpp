#include "pch.h"
#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

int CharToInt(char _value)
{
    if (_value == 'S') {
        return 1;
    }
    else if (_value == 'D') {
        return 2;
    }
    else if (_value == 'T') {
        return 3;
    }
    else
        return _value - 48;
}

int solution(string dartResult) {
    int answer = 0;
    vector<int> temps;
    int ad = 0;
    //    < 7
    for (int i = 0, count = 0; i < dartResult.size(); i += 2, ++count)
    {
        if (dartResult[i + 1] == '0') {
            ++i;
            ad = pow(10, CharToInt(dartResult[i + 1]));
        }
        else
            ad = pow(CharToInt(dartResult[i]), CharToInt(dartResult[i + 1]));

        temps.push_back(ad);

        if (i + 2 > dartResult.size())
            break;

        if (dartResult[i + 2] == '*')
        {
            ++i;

            if (count > 0)
                temps[count - 1] *= 2;
            temps[count] *= 2;

            continue;
        }
        else if (dartResult[i + 2] == '#')
        {
            ++i;

            temps[count] *= -1;

            continue;
        }

    }

    for (int i = 0; i < temps.size(); ++i)
    {
        answer += temps[i];
    }

    return answer;
}

void main()
{

    cout << solution("1D2S#10S");
}