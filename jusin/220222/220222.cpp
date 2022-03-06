#include <iostream>
using namespace std;

int main()
{
#pragma region 논리관계
	// if문에서 논리 연산자를 사용할 때, 순서를 잘 생각하자!

	int iTemp = 10, iSour = 20;

	if ((iTemp < iSour) && (iSour = 3000)) // 앞이 false면 뒤는 보지도 않는다
		cout << iSour << endl;

	if ((iTemp < iSour) || (iSour = 3000)) // 앞이 트루니 뒤는 보지도 않는다
		cout << iSour << endl;

#pragma endregion


#pragma region 구문 중복

	// if문에 if문 가능 switch도 가능

#pragma endregion


#pragma region switch문 주의사항

	int iInput = 0;
	// switch문 안에서 변수 선언은 금지!
	// 하나의 {}안에서 어떤 변수가 생겨날지 안생겨날지 분기가 생기면 모호성이 생긴다!
	// switch문에서 모호성을 없애려면 중괄호를 하나 더 넣어야함! >> 이 중괄호에는 분기가 없으니깐!!
	switch (iInput)
	{
	case 1:   // 가능!
		{
			int temp = 0;
			cout << temp << endl;
		}
		break;
	case 2:    // 불가능!
		int temp = 0;
		cout << temp << endl;
	default:
		break;
	}

#pragma endregion


#pragma region goto문

	// 키워드를 기준으로 실행할 코드와 실행시키지 않을 코드로 분기가 발생한다.

	// 성능은 뛰어나지만 단점이 너무 치명적이다!
	// 코드는 흐름이 있다(절차지향). 하지만 goto문은 이를 위배한다!
	// 흐름을 바꾸기 때문에 프로그램의 심각한 문제를 야기할 수 있다.
	// 협업을 할 때도 굉장히 작업이 어려워진다.(동료가 내 코드를 무시해버릴 수도...)

	
	goto Temp;       // 해당 키워드로 이동 된다 >> 1 출력 ㄴㄴ
	cout << 1 << endl;

	Temp:          
	cout << 2 << endl;
	

#pragma endregion
}

