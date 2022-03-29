#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> TenTo2(int _v)
{
    vector<int> s;
    vector<int> temp;
    int count = 0;

    while (1 < _v)
    {
        if (_v % 2 == 0)
            s.push_back(0);
        else
            s.push_back(1);
        _v /= 2;
        ++count;
    }

    s.push_back(1);

    for (; count < 5; ++count)
        s.push_back(0);

    for (int i = 0; i < count; ++i)
        temp.push_back(s[count - 1 - i]);

    return temp;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    // i번째 하나로도 벽이면 >> 벽
    // i번때 둘다 공백이면   >> 공백

    return answer;
}