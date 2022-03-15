#include <iostream>
#include <string>		// 문자열 관련 헤더
using namespace std;
// 문자열을 잘 다루기 위해서 만들어진 클래스 형태

void main()
{
	string strName = "홍길동";
	cout << strName << endl;

	string strNameTwo = "만만세";

	strName += strNameTwo;			// 덧셈 연산자를 통해서 문자열 결합이 가능해짐
	cout << strName << endl;

	cout << strName.length() << endl;	// 문자열 길이를 구하는 멤버 함수 존재

	if (strName == strNameTwo)			// 문자열 비교 연산자 가능
	{
		cout << "일치!" << endl;
	}
	else
		cout << "불일치!" << endl;


	char szDest[32] = "jusin";
	string s;
	s = szDest;
	cout << s << endl;
	// szDest = s.c_str();		// const char* 반환
	string s = "Hello";
	const char* pBuff = s.c_str();

	cout << sizeof(string) << endl; // 문자열 길이와 상관없이 28바이트
	// 사용적인 측면에서는 string 용량이 많다
	// c타입의 입출력에서는 문제가 된다. 하지만 나중에 가면 안 사용한다.
}