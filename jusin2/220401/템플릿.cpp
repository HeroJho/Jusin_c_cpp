#include "pch.h"

// 템플릿 : 틀, 함수 또는 클래스를 생성하기 위한 문법
// 기능은 결정되어 있지만 자료형은 결정되어 있지 않은 상태
// 인라인 함수는 치환을 통해 재활용성을 챙길 수 있지만, 자료형에 의존적이다.

// 템플릿 종류
// 함수 템플릿, 클래스 템플릿

#pragma region 함수 템플릿

	// 함수 템플릿: 함수의 모양으로 이뤄져서 함수를 생성하는 템플릿 
	// 템플릿 함수: 함수 템플릿에 의해 생성된 함수

#pragma region 단항 템플릿

// 템플릿 항이 하나인 템플릿이다.

template<typename T>
T		Add(T a, T b)
{
	return a + b;
}

#pragma endregion

#pragma region 템플릿 특수화

// 템플릿 특수화 : 특정 자료형에 해당하는 템플릿 동작을 따로 정의하는 문법
// 조건 : 모든 자료형에 해당하는 템플릿이 우선 존재해야함
template<>
char* Add(char* a, char* b)
{
	int iLength = strlen(a) + strlen(b);

	char* pString = new char[iLength + 1];

	strcpy_s(pString, iLength + 1, a);
	strcat_s(pString, iLength + 1, b);

	return pString;
}

// 특수화를 진행한 템플릿은 자료형이 명시되어 있기 때문에 함수 오버로딩 문법 또한 성립된다.
template<>
const char* Add(const char* a, const char* b) // const 오버로딩
{
	int iLength = strlen(a) + strlen(b);

	char* pString = new char[iLength + 1];

	strcpy_s(pString, iLength + 1, a);
	strcat_s(pString, iLength + 1, b);

	return pString;
}

#pragma endregion

#pragma region 이항 템플릿

// 이항 템플릿 : 두 개 이상의 타입을 갖는 템플릿

template<typename T1, typename T2, typename T3>
T3		Add(T1 a, T2 b)
{
	return a + b;
}

#pragma endregion

void main(void)
{
	// <>를 통해 자료형을 명시하는 것이 원칙이다. (안하면 컴파일러가 알아서 유추함)
	cout << Add<short>(5, 10) << endl;	// 템플릿 함수
	cout << Add<float>(3.14f, 6.27f) << endl;	// 템플릿 함수


	// 특수화된 템플릿을 사용
	char* pStr = Add<char*>("a", "b");
	cout << pStr << endl;
	delete[]pStr;
	pStr = nullptr;

	// 특수화된 템플릿 오버로딩
	const char* pConsStr = Add<const char*>("c", "d");
	cout << pConsStr << endl;
	delete[]pConsStr;
	pConsStr = nullptr;

	// 이항 템플릿
	double		dNumber = Add<int, float, double>(10, 20.1f);
	cout << dNumber << endl;

}
	
	// 템플릿 자체는 함수가 아니다.
	// 컴파일러가 템플릿을 보고 템플릿 함수를 만든다. >> 메모리 공간에 등록
	// 이 과정을 인스턴스화 라고 한다.

	// 템플릿의 단점은 코드 비대화를 야기할 수 있따 
    //    ㄴ새로운 자료형에 따라 함수를 만드니깐

	// 선언과 정의를 동시에 하면 템플릿도 인라인화 된다. 분리하면 인라인화 x

#pragma endregion

#pragma region 함수 템플릿 사용 예시
	
// SAFE_DELETE 매크로를 템플릿화해서 사용
	
#define SAFE_DELETE(p) if(p) { delete p; }

template<typename T>
void Safe_Delete(T& p)
{
	if (p) {
		delete p;
		p = nullptr;
	}
}

#pragma endregion



#pragma region 클래스 템플릿

	// 클래스 템플릿 : 클래스를 만들어내는 틀
	// 템플릿 클래스 : 클래스 템플릿으로 만들어진 클래스

#pragma region 단항 클래스 템플릿

template<typename T>
class CObj
{
private:
	T		m_X;
	T		m_Y;

public:
	CObj() {}
	CObj(T _X, T _Y) : m_X(_X), m_Y(_Y) {}
	~CObj() {}
};

void main(void)
{
	CObj<int>		IntObj(10, 20);
	CObj<float>		FloatObj(10.f, 20.f);
}

#pragma endregion

#pragma region 단항 클래스 템플릿 특수화

template<typename T>
class CObj
{
public:
	T Add(T a, T b)
	{
		return a + b;
	}
};

template<>
class CObj<char*>
{
public:
	char* Add(char* a, char* b)
	{
		int iLength = strlen(a) + strlen(b);

		char*		pString = new char[iLength + 1];

		strcpy_s(pString, iLength + 1, a);
		strcat_s(pString, iLength + 1, b);

		return pString;
	}
};

#pragma endregion


#pragma region 이항 클래스 템플릿

template<typename T1, typename T2>
class CTest
{

};

#pragma endregion

#pragma region 이항 클래스 템플릿 특수화

template<>
class CTest<int, char*>
{

};

// 부분적으로 특수화 가능하다!
template<typename T>
class CTest<T, char*>
{

};

#pragma endregion


#pragma region 템플릿의 정의부 분리

// tempalte 지시명시자는 중괄호 까지다
// 그러니 정의를 분리 했다면 다시 붙여줘야 한다
template<typename T>
class CObj
{
public:
	T Add(T a, T b);
	void	Render(T a);
};

// 정의에 그냥 CObj::를 한다면 템플릿은 클래스가 아니기 때문에 지정해주지 못한다
// <T> 를 붙여서 템플릿이라는 것은 명시해 줘야 한다.
template<typename T>
T CObj<T>::Add(T a, T b)
{
	return a + b;
}
template<typename T>
void	CObj<T>::Render(T a)
{
	cout << a << endl;
}

// 즉, template을 분리해서 구현하면 전부 template 명시자를 붙여야 한다.
// 그래서 그냥 선언과 정의를 분리 안하는 경우가 많다. >> 인라인도 챙기고

#pragma endregion


#pragma region 클래스 템플릿의 상속

// 상속 역시 다음과 같이 가능하다.
// T를 넘겨주는 느낌으로 명시해 주면된다.
template<typename T>
class CMonster : public CObj<T>
{

};

#pragma endregion


#pragma endregion


#pragma region static과 템플릿의 관계

// 템플릿 내에 선언한 static 변수는 같은 자료형의 템플릿인 경우에만 메모리를 공유한다.

#pragma region 함수

template<typename T>
T Func(T Num)
{
	static T Temp = 0;

	Temp += Num;

	return Temp;
}

#pragma endregion


#pragma region 클래스

template<typename T>
class CObj
{
private:
	static T	m_Temp;

public:
	T Func(T Num)
	{
		m_Temp += Num;

		return m_Temp;
	}
};
// 초기화 해줄때도 명시. >> 그냥 명시 중괄호 떨어지면 또 명시!!
template<typename T>
T CObj<T>::m_Temp = 0;

#pragma endregion

void main(void)
{
	// 함수
	Func<int>(10);
	Func<double>(20.1);
	cout << Func<int>(5) << endl;
	cout << Func<double>(3.14) << endl;

	// 클래스
	CObj<int>		intObj;
	CObj<int>		intObj2;
	CObj<double>	doubleObj;

	intObj.Func(10);
	intObj2.Func(20);
	cout << intObj.Func(0) << endl;

	doubleObj.Func(20.1);
	cout << intObj.Func(5) << endl;
	cout << doubleObj.Func(3.14) << endl;

}


#pragma endregion


#pragma region 정리

/*

1. 모든 자료형을 호환한다.
2. 템플릿이 사용되는 형식은 컴파일 타임에 이뤄지기 때문에 오류가 발생하기 전에 컴파일러가 검사를 수행하여 안전하다.
3. 컴파일러가 함수 또는 클래스를 생성해주기 때문에 생성속도가 빠르다.

1. 자료형의 개수가 많아질수록 일일이 생성하기 때문에 코드 비대화를 불러온다.

// 근데 템플릿 안 쓰고 내가 일일히 필요한 자료형의 함수, 
// 클래스 만들어서 써도 코드 비대화나는건 같지 않나요?
//		ㄴ인스턴스화 되어서 비대화가 일어난다는 것 >> 맞다 하지만 템플릿을 사용하면 남발 될 수 있다.

2. 실행파일의 크기가 커진다.

*/

#pragma endregion

// 주말 숙제 자료구조보고 코드 따라치기 >> 리스트까지는 구현해보기
