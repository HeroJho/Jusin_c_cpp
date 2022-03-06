#include <iostream>
using namespace std;

// 3. ���Ǳ� �Լ� ���� �����ϱ� (while�� �̿��ؼ�)

void ShowMyMoney(const int* _iMoney)
{
	cout << "�ܾ�: " << *_iMoney << endl << endl;
	system("pause");
}
void ShowMenu()
{
	cout << "===== �޴� =====" << endl;
	cout << "1.�ݶ�(100��)  2.���̴�(200��)  3.ȯŸ(300��)  4.��ȯ : ";
}
void BuyItem(int* _iMoney, int _iBuy)
{
	*_iMoney -= _iBuy;
}
bool CompMoney(int* _iMoney, int _iBuy)
{
	if (*_iMoney - _iBuy < 0)
		return false;

	BuyItem(_iMoney, _iBuy);

	return true;
}

int main()
{
	int iMoney = 0;
	int iSelect = 0;
	cout << "�ܾ��� �Է��� �ּ���!: ";
	cin >> iMoney;

	while (true)
	{
		ShowMyMoney(&iMoney);
		system("cls");

		ShowMenu();
		cin >> iSelect;

		switch (iSelect)
		{
		case 1:
			if (CompMoney(&iMoney, 100))
				cout << "���ִ� �ݶ� ����ϴ�!" << endl;
			else
				cout << "�ܾ��� �����մϴ�!" << endl;
			break;

		case 2:
			if (CompMoney(&iMoney, 200))
				cout << "���ִ� ���̴ٸ� ����ϴ�!" << endl;
			else
				cout << "�ܾ��� �����մϴ�!" << endl;
			break;

		case 3:
			if (CompMoney(&iMoney, 300))
				cout << "���ִ� ȯŸ�� ����ϴ�!" << endl;
			else
				cout << "�ܾ��� �����մϴ�!" << endl;
			break;

		case 4:
			cout << "���Ǳ⸦ �����ϴ�..." << endl;
			break;

		default:
			cout << "�ش� �޴��� �����ϴ�!" << endl;
			break;
		}

		if (iSelect == 4)
		{
			cout << "�ܾ��� " << iMoney << "�� �Դϴ�." << endl;
			break;
		}

	}
}