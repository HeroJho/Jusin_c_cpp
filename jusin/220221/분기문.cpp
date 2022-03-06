#include<iostream>
using namespace std;

int main()
{
	// 분기문: 기준을 잡아서 나누는 문법
	// if문, switch문, goto문

#pragma region if문
	// '{}'는 코드를 지역으로 분리한다
	// '()'(스위치)안의 조건문이 만족하면 {}의 지역 코드를 실행한다

	int temp = 0;
	cin >> temp;
	if (temp > 10)
	{
		cout << 1 << endl;
	}
	else  // if 조건이 false면 실행!
		cout << 2 << endl;   // 한 줄 코드는 중괄호 생략 가능.
	// else를 사용하려면 if문이 먼저 만들어져 있어야 한다!
	
	int iInput = 0;
	cout << "숫자를 입력하세요(1. 빨강 2. 노랑 3. 파랑): ";
	cin >> iInput;
	
	// else if을 사용하면 공통적인 조건분기를 만들 수 있따 >> if문 여러개가 아니라...(개별적인 if문)
	// else if도 if문이 선행돼야 한다!
	if (1 == iInput)// 변수와 상수 비교때 변수가 오른쪽으로 !!
		cout << "빨강" << endl;
	else if (2 == iInput)
		cout << "노랑" << endl;
	else if (3 == iInput)
		cout << "파랑" << endl;
	else    // 모든 조건문이 전부 false일 때
		cout << "잘못된 입력입니다!" << endl;
#pragma endregion


#pragma region switch문

	// 상수를 이용하여 분기하는 문법, 상수 조건 분기문이라고도 한다.
	// 조건으로 상수 또는 정수만 취급하며, 실수로는 분기할 수 없다.

	int iSelect = 0;
	cin >> iSelect;

	switch (iSelect)
	{
	case 1: // 반드시 case 옆에 상수가 와야한다! 변수 x!
		cout << '1' << endl;
		break;  // 여기 까지만 실행하고 멈춰라! 없으면 모든 case출력함.
				// 만나면 바로 {}를 바로 벗어난다!
	case 2:
		cout << '2' << endl;
	case 3:
		cout << '3' << endl;
	default:  // 조건 만족이 없을 때 예외처리! 전부 여기 걸린다!
		cout << "잘못 입력했어" << endl;
		break;
	}
	// switch는 큼직큼직한 분기(게임의 스테이지 구분)에서 사용된다.
	// 유지보수가 편하다! if문은 짤막짤막한(hp같은 조건)곳에 사용

#pragma endregion

}

// 숙제 : 성적 입출력 프로그램
// 1. 국영수 입력 받고 총점 평균 구함
// 2. if문을 이용해서 평균 점수에 따라 성적 등급을 매긴다.
//		ㄴ조건: 90점 이상 100점 이하 A,
//				80점 이상 90점 미만 B,
//				70점 이상 80점 미만 C,
//				60점 이상 70점 미만 D,
//				나머지 F,

// if문 버전과 switch버전 둘 다 만들어보기