#include <iostream>
#include <vector>
using namespace std;

// LvalueRvalueReferans

#pragma region R-value와 L-value

	// L - value : 연산자를 기준으로 왼쪽, 오른쪽 모두 등장할 수 있는 값
	// R - value : 연산자를 기준으로 오른쪽에만 존재할 수 있는 값

int main()
{
	// iTemp 는 대입 연산자 기준으로 왼쪽, 오른쪽 모두 위치 = L-value
	// 숫자 10은 오른쪽에만 있을 수 있기					= R-value

	int	iTemp = 10;
	int	iDest = iTemp;
}

#pragma endregion



#pragma region R-value 레퍼런스

// - R-value의 값도 주소값 참조가 가능하도록 하는 문법.

// - 데이터 복사 비용을 최소화 하기 위해 자주 사용하는 문법.
void	Add(int&& a, int&& b)
{
	//a += 10;
	//b += 20;
}


int main()
{
	int		iTemp = 20;

	// 일반적인 레퍼런스는 L-value만 참조할 수 있다.
	//    ㄴ상수값은 >> 임시 메모리 >> 참조 불가능
	int&	r = 10;	

	// const를 붙이면 참조하겠다는 것이 아니라 읽기 전용을 사용하겠다는 말
	const int& r = 10;


	// 그러면 상수값을 레퍼런스로 받고, 변경까지 가능하게 하려면 어떻게 해야해?
	//  ㄴ함수의 인자로 넘겨줄 때 복사를 막기 위해서

	
	// R-value의 값도 주소값 참조 가능
	// R-value 레퍼런스 자료형은 L-value 값 대입도 가능
	int&& r2 = 10;
	r2 = 20;

	cout << r2 << endl;


	// 상수를 인자로 복사 과정없이 넘겨줄 때 사용된다.
	int iA = 10;
	int	iB = 20;
	
	Add(iA, iB);
	Add(10, 20);
}

#pragma endregion


#pragma region 이동 생성자 (R-value 응용)

// - 따로 복사과정을 진행하지 않고(복사 생성자) 객체를 이전만 한다. (얇은 복사 후 원본 nullptr)
// - 즉, 소유권 이전을 하는 생성자이다.
// - 이동 생성자가 호출되기 위해서 R-value 레퍼런스 자료형으로 인자를 받는다.

class CObj
{
public:
	CObj() : m_pArray(nullptr), m_iSize(0)
	{
	}
	CObj(int iSize) : m_pArray(new int[iSize]), m_iSize(iSize)
	{
	}

	// 복사 생성자
	CObj(CObj& rObj)
	{
		m_pArray = new int[rObj.m_iSize];
		memcpy(m_pArray, rObj.m_pArray, sizeof(int) * rObj.m_iSize);
		m_iSize = rObj.m_iSize;
	}

	// 이동 생성자
	CObj(CObj&& rObj)
	{
		m_pArray = rObj.m_pArray;		// 소유권 이전
		m_iSize = rObj.m_iSize;

		// 소유권 이전 이후 댕글링 포인터가 되지 않도록 null로 초기화
		rObj.m_pArray = nullptr;
	}

	~CObj()
	{
		if (m_pArray)
		{
			delete[]m_pArray;
			m_pArray = nullptr;
		}
	}

private:
	int*			m_pArray;
	int				m_iSize;
};

void main(void)
{
	// std::move : 매개변수로 전달받은 대상을 R-Value 레퍼런스로 캐스팅해주는 함수
	// move 함수를 사용하여 이동생성자를 호출할 지, 아니면 복사 생성자를 호출할지 구문하게 됨

#pragma region 객체의 이동 생성자 호출

	CObj		Obj(100000000);

	DWORD		dwTime = GetTickCount();

	//CObj		Temp(Obj);					// 복사 생성자 호출. >> 많은 시간 소요

	CObj		Temp(std::move(Obj));		// 얇은 복사 후, 포인터 nullptr >> 이전이라 복사x >> 단 시간 끝

	cout << (GetTickCount() - dwTime) << endl;

#pragma endregion


#pragma region vector의 이동 생성자 호출

	vector<CObj>		vec;

	// **!! 여기서 넣어주는 CObj자체가 임시 객체(Rvalue)라 바로 이동 생성자가 호출된다.

	// 복사 생성자를 통한 데이터 이전 과정
	vec.push_back(CObj(100000000));

	// 1. 임시 객체 생성 및 할당
	// 2. 할당 과정에서 동적 멤버 할당
	// 3. 깊은 복사 생성자 호출, 복사 수행 시, 1억에 해당하는 데이터 복사 비용 소모
	// 4. 복사 수행 후 임시 객체 소멸자 호출
	// 5. 임시 객체 멤버 해제
	// 6. 임시 객체 소멸
	

	// 이동 생성자를 통한 데이터 이전 과정
	vec.push_back(std::move(CObj(100000000)));

	// 1. 임시 객체를 할당
	// 2. 할당 과정에서 동적 멤버 할당
	// 3. 이동생성자를 통한 소유권 이전(1번 항목의 주소만 이동)
	// 4. 소유권 이전 후, 임시 객체 소멸자 호출
	// 5. 임시 객체 소멸

#pragma endregion


#pragma region 벡터와 벡터 간의 이동


	vector<int>		vec1(100000000);

	DWORD	dwTime = GetTickCount();

	cout << "vec1.capacity  : " << vec1.capacity() << endl;

	vector<int> vec2 = std::move(vec1);
	cout << "vec2.capacity  : " << vec2.capacity() << endl;
	cout << "시간 : " << (GetTickCount() - dwTime) << endl;


#pragma endregion

}

#pragma endregion



#pragma region 정리

void Func(int&& a)
{
	a = 50;
	// cout << a << endl;
}

int main()
{
	int num1 = 20;

	// Rvalue 참조자 자료형은 Rvalue만 받을 수 있다.
	int&& num2 = num1;

	// std::move()함수를 통해 Lvalue를 Rvalue로 바꿀 수 있다.
	int&& num2 = std::move(num1);

	// 결국 참조자야.
	// Lvalue 참조자는 그냥 참조자 사용하면 된다.

// ===============================================================

	// 왜 Lvalue를 Rvalue로 바꿔서 Rvalue 참조자로 받아서 사용하냐?
	//	ㄴ복사 생성자는 원본을 Lvalue 참조자를 받는다.
	//	ㄴ똑같이 이동 생성자도 원본을 받아와야 한다.
	//	ㄴ그렇다면 복사 생성자와 이동 생성자를 구분할 방법이 없다.
	//	ㄴ그래서 Lvalue 참조자와 Rvalue 참조자를 받는 생성자로 구별해서 구별한다.


	return 0;
}

#pragma endregion
