#include "pch.h"

class CName
{
	// 멤버 변수에 포인터를 가지고 있는지 확인
	// 있으면 깊은복사인지 확인 필요함
	// 소멸자에서 해당 포인터 주소를 해제하는 코드가 있는지 >> 없으면 필요없음
private:
	char* m_pName;

public:
	CName(const char* pName)
	{
		int iLength = strlen(pName);
		m_pName = new char[iLength + 1];
		strcpy_s(m_pName, iLength + 1, pName);
	}

	CName(const CName& pName)
	{
		int iLength = strlen(pName.m_pName);		// 깊은 복사

		m_pName = new char[iLength + 1];
		strcpy_s(m_pName, iLength + 1, pName.m_pName);
	}

	void Print(int a) const
	{
		cout << m_pName << endl;
	}

	~CName()
	{
		if (m_pName != nullptr)
			delete[] m_pName;
	}
};

void main()
{
	// 스택 >> 후입 선출로 해제(소멸자 호출)
	CName A("hero");
	CName B(A);

	// B의 디폴트 복사 생성자를 호출
	// 주소대 주소 복사가 일어남 (얕은 복사 생성자 shallow copy)
	// 두 개의 포인터가 같은 객체를 가리켜서 생기는 문제
	
	// 해결 방법
	// 각각의 다른 주소를 가리키도록 복사 생성자를 정의한다.(객체 복사)

	A.Print();
}