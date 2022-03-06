#include <iostream>
using namespace std;

// 3. 자판기 함수 버전 구현하기 (while을 이용해서)

void ShowMyMoney(int _iMoney)
{
	cout << "잔액: " << _iMoney << endl << endl;
	system("pause");
}
void ShowMenu()
{
	cout << "===== 메뉴 =====" << endl;
	cout << "1.콜라(100원)  2.사이다(200원)  3.환타(300원)  4.반환 : ";
}
bool CompMoney(int _iMoney, int _iBuy)
{
	if (_iMoney - _iBuy < 0)
		return false;

	return true;
}

int main()
{
	int iMoney = 0;
	int iSelect = 0;
	cout << "잔액을 입력해 주세요!: ";
	cin >> iMoney;

	while (true)
	{
		ShowMyMoney(iMoney);
		system("cls");

		ShowMenu();
		cin >> iSelect;

		switch (iSelect)
		{
		case 1:
			if (CompMoney(iMoney, 100))
			{
				iMoney -= 100;
				cout << "맛있는 콜라를 삿습니다!" << endl;
			}
			else
				cout << "잔액이 부족합니다!" << endl;
			break;

		case 2:
			if (CompMoney(iMoney, 200))
			{
				iMoney -= 200;
				cout << "맛있는 사이다를 삿습니다!" << endl;
			}
			else
				cout << "잔액이 부족합니다!" << endl;
			break;

		case 3:
			if (CompMoney(iMoney, 300))
			{
				iMoney -= 300;
				cout << "맛있는 환타를 삿습니다!" << endl;
			}
			else
				cout << "잔액이 부족합니다!" << endl;
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

