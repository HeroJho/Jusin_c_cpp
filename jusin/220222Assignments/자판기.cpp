#include <iostream>
using namespace std;

// 3. 자판기 구현하기 (while을 이용해서)
//	- 소지금 입력 받기
//	- 현재 소지금을 잔액 으로 표기하여 출력
//	- 메뉴가 출력, 1.콜라(100원) 2.사이다(200원) 3.환타(300원) 4.반환
//	- 선택에 의해 구매 시 잔액은 바뀌어야함
//	- 소지금이 부족할 겅우 구매는 불가능하고, 잔액이 부족합니다 출력
//	- 4번을 누르면 잔액은 --원입니다. 출력 후 프로그램을 총료.
int main()
{
	int iMoney = 0;
	int iSelect = 0;
	cout << "잔액을 입력해 주세요!: ";
	cin >> iMoney;

	while (true)
	{
		cout << "잔액: " << iMoney << endl << endl;
		system("pause");
		system("cls");

		cout << "===== 메뉴 =====" << endl;
		cout << "1.콜라(100원)  2.사이다(200원)  3.환타(300원)  4.반환 : ";
		cin >> iSelect;

		switch (iSelect)
		{
		case 1:
			if (iMoney - 100 < 0)
				cout << "잔액이 부족합니다!" << endl;
			else
			{
				iMoney -= 100;
				cout << "맛있는 콜라를 삿습니다!" << endl;
			}
			break;
		case 2:
			if (iMoney - 200 < 0)
				cout << "잔액이 부족합니다!" << endl;
			else
			{
				iMoney -= 200;
				cout << "맛있는 사이다를 삿습니다!" << endl;
			}
			break;
		case 3:
			if (iMoney - 300 < 0)
				cout << "잔액이 부족합니다!" << endl;
			else
			{
				iMoney -= 300;
				cout << "맛있는 환타를 삿습니다!" << endl;
			}
			break;
		case 4:
			cout << "자판기를 떠납니다..." << endl;
			break;
		default:
			cout << "해당 메뉴는 없습니다!" << endl;
			break;
		}

		if (iSelect == 4)
		{
			cout << "잔액은 " << iMoney << "원 입니다." << endl;
			break;
		}

	}
}