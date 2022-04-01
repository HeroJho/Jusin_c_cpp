// string클래스
// ==(strcmp), +(strcat), =(strcpy) 오버로딩 해보기

#include <iostream>
using namespace std;

#pragma warning(disable:4996)

class String
{
public:
    char* m_cTemp;
public:
    bool operator==(const String& ref)
    {
        return !strcmp(m_cTemp, ref.m_cTemp);
    }
    String operator+(const String& ref)
    {
        String s;
        s.m_cTemp = new char[strlen(m_cTemp) + strlen(ref.m_cTemp) + 1];
        strcpy(s.m_cTemp, m_cTemp);
        strcat(s.m_cTemp, ref.m_cTemp);

        return s;
    }
    String& operator=(const String& _ref)
    {
        if (m_cTemp != nullptr)
            delete m_cTemp;

        m_cTemp = new char[strlen(_ref.m_cTemp) + 1];
        strcpy(m_cTemp, _ref.m_cTemp);
        return *this;
    }

public:
    String() : m_cTemp(nullptr) {}
    String(const char* _cTemp)
    {
        m_cTemp = new char[strlen(_cTemp) + 1];
        strcpy(m_cTemp, _cTemp);
    }
    String(const String& _ref)
    {
        if (m_cTemp != nullptr)
            delete m_cTemp;

        m_cTemp = new char[strlen(_ref.m_cTemp) + 1];
        strcpy(m_cTemp, _ref.m_cTemp);
    }
    ~String()
    {
        if (m_cTemp != nullptr)
            delete m_cTemp;
    }

};

int main()
{
    String s1 = "Hero";
    String s2 = "Hero";
    String s3 = s1 + s2;

    cout << s3.m_cTemp << endl;

    if (s1 == s2)
        cout << "같습니다!" << endl;
    else
        cout << "다릅니다!" << endl;


    s1 = s2 = s3;
    cout << s1.m_cTemp << endl;
    cout << s2.m_cTemp << endl;
    cout << s3.m_cTemp << endl;
}
