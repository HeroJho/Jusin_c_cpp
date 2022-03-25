#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;

    int temN = n;
    for (int i = strings.size() - 1; i > 0; --i)
    {
        for (int j = 0; j < i; ++j)
        {
            if (strings[j][temN] == strings[j + 1][temN])
            {
                ++temN;
                --j;
                continue;
            }

            if (strings[j][temN] > strings[j + 1][temN])
            {
                string temp = strings[j];
                strings[j] = strings[j + 1];
                strings[j + 1] = temp;
            }

            temN = n;
        }
    }

    return strings;
}

void main()
{
    vector<string> st;

    st.push_back("abzcd");   // 
    st.push_back("cdzab");
    st.push_back("abzfg");
    st.push_back("abzaa");
    st.push_back("abzbb");
    st.push_back("bbzaa");

    st = solution(st, 2);

    for (int i = 0; i < st.size(); i++)
    {
        cout << st[i] << endl;
    }
}