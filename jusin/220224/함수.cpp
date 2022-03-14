#include <iostream>
using namespace std;

void Func(); // 함수만 선언!
void Print(int);
int Get_Temp(void);
int Add(int, int);

int main()
{
#pragma region 함수

	// 사전적 개념: 코드를 재사용 하겠다. (더하기 기능은 많이 쓰니, 한 번 만들어서 필요할 때마다 쓰겠다)
	// 함수란 어떤 상자에 입력을 넣으면 가공을 해서 출력을 하는 것이다
	// 컴파일을 하면 컴파일러는 함수를 스캔해서 어떤 메모리 공간에 등록해 둔다 (코드 영역)
	// 코드의 흐름을 생각해서 함수의 선언은 맨 앞에 해줘야 한다.
	//	ㄴ정의도 앞에서 해줘도 된다! 어떤 함수가 있는지 컴파일러한테 미리 알려주기만 하면 된다.
	
	Func();  // 메모리에 저장된 함수를 호출!
	Func();
	Func();  

	Print(10);

	cout << Get_Temp() << endl;

	Print(Get_Temp()); // 이처럼 함수인자로 함수를 넣을 수 있다.
	// 함수안에서 함수를 호출할 수 있따

	Add(Get_Temp(), 50);

#pragma endregion
}

// 함수를 만들 때는 함수 밖에서 만든다(정의한다)
void Func(void)   // 함수의 선언: 반환타입 / 함수이름 / 매개변수
{				  // 함수의 정의(몸체)
	cout << "hello" << endl;
}

// 함수의 형태는 4가지로 분리 될 수 있다.
// 반환       매개
// void Func (void) : 입력도 없고 출력(가공된 값)없고

// void Func (int 이름) : 입력, 출력 ㄴ
void Print_PlusOne(int _iA)
{
	cout << _iA + 1 << endl;
}

// int Func (void) : 입력 ㄴ, 출력 0
// 반환타입: 어떤 자료형으로 반환을 해줘야하나
// 반환타입이 void가 아니면 반드시 return을 해줘야한다.
// return : 현재 사용중인 함수를 종료해라!
int Get_Temp(void)
{
	// 반환 타입이 void라면 return만 사용해도 되지만, 아니라면 무언갈 반환해야 한다.
	return 400;
}

// int Func (int) : 입력 0 출력 0
int Add(int _iTemp1, int _iTemp2)
{
	return _iTemp1 + _iTemp2;
}


// 숙제:
// 1.함수를 이용해서 자판기 코드를 수정해 보기.

