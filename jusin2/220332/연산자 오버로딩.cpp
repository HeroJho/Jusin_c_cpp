#include "pch.h"

// 필기* 연산자 오버로딩한 클래스
#pragma region 연산자 오버로딩 코드

class CObj
{
private:
	int		m_iX;
	int		m_iY;

public:
	void		Render() { cout << m_iX << "\t" << m_iY << endl; }

	CObj		operator + (CObj& rObj)	// + 연산자를 오버로딩한 예
	{
		CObj	Test(m_iX + rObj.m_iX, m_iY + rObj.m_iY);

		return Test;
	}
	CObj		operator + (int _iMove)	// + 연산자를 오버로딩한 예
	{
		CObj	Test(m_iX + _iMove, m_iY + _iMove);

		return Test;
	}

	// 대입 연산자 오버로딩
	// 깊은 복사 얕은 복사 신경쓰기!
	CObj& operator =(CObj& rObj)
	{
		m_iX = rObj.m_iX;
		m_iY = rObj.m_iY;

		return *this;
	}


	// 단항 연산자 오버로딩
	CObj& operator ++(void) // 전위
	{
		m_iX += 1;
		m_iY += 1;

		return *this;
	}
	// 후위
	CObj operator ++(int) // int 형 데이터를 받는 것이 아니라 오버로딩을 위한 구분 문법
	{
		CObj	Test(*this);

		m_iX += 1;
		m_iY += 1;

		return Test;
	}


public:
	CObj() {}
	CObj(int _iX, int _iY) : m_iX(_iX), m_iY(_iY) {}
	~CObj() {}
};

// 교환 법칙 해결 시 전역 함수 만들어줘야 함. 
// 객체 타입에는 객체 포인터가 아닌 순수 객체 타입과 객체의 레퍼런스 타입이 와야한다.
// operator+에는 클래스 형식의 정식 매개 변수가 적어도 하나는 있어야 한다.
CObj	operator +(int _iMove, CObj& rObj)
{
	CObj		Test(rObj + _iMove);

	return Test;
}

#pragma endregion


int main()
{
#pragma region 연산자 오버로딩이란?

	CObj Temp(100, 200);
	CObj Sour(300, 400);

	CObj Dest = Temp + Sour;  // 어떻게 더해라고?
	// 우리가 생각하는 형태로 연산자의 함수를 만들어 주자는 것

	// 연산자 오버로딩: 연산자에 적용을 시킨 함수 오버로딩의 문법 
	// >> 실제로 사용 잘 없다(다 만들어서 제공된다) >> Stl 조건자를 위해 배운다
	// 연산자 오버로딩을 달달 볶을 정도로 할 필요는 없다!!

	// 1. 본래 연산자의 기능을 뒤바꿀 쑨 없다.
	// 2. 사용자 정의 자료형일 때 성립하는 문법이다.
	// 3. 클래스 멤버로만 존재할 수 있는 연산자 =, (), [], ->, 좌측 기준으로만 연산을 수행하는 연산자들 
	//	ㄴ(사칙연산은 그냥 되는 것)

#pragma endregion


#pragma region 교환 법칙

	// 호출 객체는 왼쪽, 오른쪽이 인자 >> 교환 법칙이 성립하질 않는다!
	// Temp.+(Sour);
	// 교환법칙 해결 시 전역 함수로 만들어야 한다. 
	// 객체 타입에는 객체 포인터가 아닌 순수 객체 타입과 객체의 레퍼런스 타입이 와야한다.
	// operator+에는 클래스 형식의 정식 매개 변수가 적어도 하나는 있어야 한다.

#pragma endregion


#pragma region 대입 연산자 오버로딩

	// 디폴트 대입 연산자 존재.
	// 얕은 대입 연산 >> 깊은 대입 연산으로 만들기
	
#pragma endregion


#pragma region 단항 연산자 오버로딩

	// ++, --

	// 전위
	// 자신을 반환한다 (연달아서)
	++(++Temp);

	// 후위는 어떻게 만들어?
	// 함수 인자에 int를 붙여서 오버로딩을 위한 구분 문법을 사용한다.(명시용)
	// 후위는 객체를 만들어서 반환한다 (연달아 x)

#pragma endregion


	
#pragma region cout << 연산자 오버로딩
	
	// cout도 클래스다

	/*
namespace MyStd
{
	class Ostream
	{
	public:
		Ostream&	operator <<(int iDest)
		{
			printf("%d", iDest);

			return *this;
		}

		Ostream&	operator <<(char* pDest)
		{
			printf("%s", pDest);

			return *this;
		}
	};

	Ostream		COUT;
	char*		ENDL = "\n";

}

using namespace MyStd;

void main(void)
{
	COUT << 100 << ENDL;
}
*/

#pragma endregion



#pragma region () 연산자 오버로딩과 펑터

#pragma region 코드

#pragma region 기본 구현
/*
class CObj
{
public:
	int	operator() (int iTemp, int iSour)
	{
		return iTemp + iSour;
	}
};

void main(void)
{
	CObj	Obj;
	cout << Obj(10, 20) << endl;
}*/
#pragma endregion


#pragma region 정렬 바꾸기
/*
class CSortRule
{
public:
	virtual bool	operator()(int iTemp, int iSour) = 0;
};

// 오름차순
class CAsendingSort : public CSortRule
{
public:
	virtual bool operator()(int iTemp, int iSour)
	{
		if (iTemp > iSour)
			return true;

		return false;
	}

};

// 내림차순
class CDesendingSort : public CSortRule
{
public:
	virtual bool operator()(int iTemp, int iSour)
	{
		if (iTemp < iSour)
			return true;

		return false;
	}
};

void	Bubble_Sort(int* pArray, int iSize, CSortRule& Functor)
{
	for (int i = 0; i < iSize; ++i)
	{
		for (int j = 0; j < iSize - 1; ++j)
		{
			if (Functor(pArray[j], pArray[j+1]))
			{
				int	iTemp = pArray[j];
				pArray[j] = pArray[j + 1];
				pArray[j + 1] = iTemp;
			}
		}
	}
}

void main(void)
{
	int		iArray[5] = { 1, 3, 4, 2, 5 };

	CAsendingSort		Asen;
	CDesendingSort		Desen;

	Bubble_Sort(iArray, 5, Desen);

	for (int i = 0; i < 5; ++i)
	{
		cout << iArray[i] << endl;
	}

}*/
#pragma endregion

#pragma endregion
	
	// 함수 객체(펑터) : ()연산자 오버로딩을 통해 객체를 함수처럼 사용하는 문법
	// STL은 함수 객체를 만들어 함수 대신 사용한다 >> 조건자

	// 왜 사용해?
	// 다형성(오버라이딩)을 이용해 함수를 유연하게 사용하기 위해서
	// 오름차순 내림차순 예제 >> 조건자 예제

	// 같은 호출 문장에라도 실제 어떤 객체냐에 따라 각기 다른 상태를 표현할 수 있다.
	// 함수 객체가 클래스 선언부에 몸체까지 정의되어 있따면 해당 멤버 함수는 자동 inline화 되어 일반 함수에 비해 속도가 빠르다
	// inline화 햇는데 virtual를 쓰면 속도가 줄어드니 모순! >> virtual을 잘 안 한다.(상속)

#pragma endregion


#pragma region 임시 메모리

	// 임시 객체
CObj("임시 객체"); // 임시 객체는 해당 코드라인을 벗어나면 소멸된다.
// 바로 소멸

// 함수 펑터들은 임시 객체로 사용해 메모리 효율을 높인다

#pragma endregion

}

// string클래스
// ==(strcmp), +(strcat), =(strcpy) 오버로딩 해보기