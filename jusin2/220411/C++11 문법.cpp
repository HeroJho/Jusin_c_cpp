#include <iostream>
#include <vector>
#include <map>
#include <array>
using namespace std;


#pragma region mutable

// - 읽기 전용 함수 내에서 값 변경이 가능하도록 해주는 키워드

class CObj
{
private:
	mutable int			m_iA;		// 사용!
	int			m_iB;

public:
	void		Render() const // 읽기 전용(데이터 변경 불가능)
	{
		m_iA = 30;
		//m_iB = 40;
	}

public:
	CObj() : m_iA(10), m_iB(20){	}
};

#pragma endregion


#pragma region try-catch

// - c++의 예외처리 문법이다.
// - if문의 경우 일반적인 프로그램의 논리를 구현하는데 주 목적을 둔다.
// - 예외 처리만의 문법이 필요하다.


int main()
{
	int		iNum1, iNum2;

	cout << "숫자 입력 : ";
	cin >> iNum1 >> iNum2;

	// if-else의 예외처리
	if (0 == iNum2)
		cout << "0으로 나눌 수 없습니다" << endl;
	else
	{
	cout << "몫 : " << (iNum1 / iNum2) << endl;
	cout << "나머지 : " << (iNum1 % iNum2) << endl;
	}


	// try-catch의 예외처리
	try
	{
		if (0 == iNum2)
			throw iNum2;	// 데이터를 catch에 throw한다!

		// 위에서 정한 예외가 발생하면 나머지 코드 블록은 실행하지 않고 건너 뛴다.
		cout << "몫 : " << (iNum1 / iNum2) << endl;
		cout << "나머지 : " << (iNum1 % iNum2) << endl;
	}
	catch (int iNum2)
	{
		cout << "0으로 나눌 수 없습니다" << endl;
	}

	return 0;
}


#pragma endregion


#pragma region auto

// - 사용자가 직접 타입을 지정하지 않아도 되는 문법
// - 편리하긴 하지만, 남발할 시 혼란을 야기할 수 있다.
// - 선언과 동시에 초기화를 해줘야 한다.
// - 컴파일러에게 판단권을 맡긴다. >> 좋지 않다!
// - 이처럼 단점도 있기 때문에 조금 기피하는 경향이 있다

int main()
{
	auto	i = 10;
	cout << sizeof(i) << endl;

	auto	l = 10l;
	cout << sizeof(l) << endl;

	auto	f = 3.14f;
	cout << sizeof(f) << endl;

	auto	p = new int;
	cout << sizeof(p) << endl;

	// 반복자 사용을 간단하게 할 수도 있다.
	vector<int>			vecInt;
	vector<int>::iterator		iter = vecInt.begin();
	auto	iter = vecInt.begin();
}


#pragma endregion


#pragma region 범위 기반 for문

// - 간단하고, 배열 인덱스 범위를 넘어가는 행동을 방지할 수 있다.

int main()
{
	int	iArray[5] = { 0, 1, 2, 3, 4 };

	for (int i : iArray)
		cout << i << endl; 


	vector<int>	vec;
	vec.push_back(10);
	vec.push_back(20);
	vec.push_back(30);
	vec.push_back(40);
	vec.push_back(50);

	// 참조자로 받으면 원본값 변경 가능
	for (auto& iter : vec)
	{
		iter += 5;
		cout << iter << endl;
	}
}

#pragma endregion 


#pragma region 유니폼 초기화

struct tagInfo
{
	int X;
	int Y;
};

class  CObj
{
public:
	tagInfo		Get_Info()
	{
		return { 400, 100 };
	}

public:
	CObj(tagInfo _tInfo)
		: m_tInfo(_tInfo)
	{

	}
private:
	tagInfo		m_tInfo;
};

int main()
{
	int	iArray[5] = { 0, 1, 2, 3, 4 };
	// 유니폼 초기화
	int	iArray[5]{ 0, 1, 2, 3, 4 };		
	
	// struct 유니폼 초기화
	tagInfo	tInfo{ 10 , 20 };
	
	// class 유니폼 초기화
	//   ㄴprivate 멤버를 유니폼 초기화 할 때는 반드시 매개변수가 있는 생성자가 있어야 성립한다.
	CObj	Obj{ {100, 200} };

	// vector 유니폼 초기화
	vector<int>		vec{ 10, 20, 30, 40, 50 };
	cout << vec.size() << "\t" << vec.capacity() << endl;

	// map 유니폼 초기화
	map<int, int>	MyMap{ {1, 100},{ 2, 200 },{ 3, 300 } };
	for (auto mapiter : MyMap)
		cout << mapiter.first << "\t" << mapiter.second << endl;
}

#pragma endregion


#pragma region std::array

// - stl에서 제공해주는 "정적 배열"이다.
// - #include<array>를 붙여줘야 한다.
// - 기존에 사용하던 정적 배열을 객체화 함.
//		ㄴ생성자, 소멸자, 복사 생성자, 대입 연산자가 지원되어 좀 더 객체지향 다운 배열로 생성 가능하다.
//		ㄴ반복자, empty, swap, front, back 함수를 제공.
// - 벡터는 동적 배열이어서 사용 비용이 크다. 
//      ㄴ크기가 이미 정해진 경우라면 array를 사용하는 것이 좋다.


int main()
{
	array<int, 5> arrEx; // { 1, 2, 3 };
	cout << sizeof(arrEx) << endl;

	int*	p = arrEx.data();	// 배열의 첫 주소를 반환하는 함수

	arrEx.fill(999);	// 배열의 모든 원소를 인자값으로 채워주는 함수
	
	for (int i : arrEx)
		cout << i << endl;


	array<int, 5> arrTemp;

	arrTemp = arrEx;		// 서로 간의 대입을 통한 값 복사가 가능하다
}

#pragma endregion



#pragma region 정적 vs 동적

// 정적 동적 >> 정적은 컴파일 타임에 결정이 나서 런타임에 작업할 일이 없다.
// 동적은 정적보다 유틸성을 강조한 거지, 성능이나 용량을 생각하면 동적이 좋다.

#pragma endregion