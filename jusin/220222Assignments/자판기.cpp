#include <iostream>
using namespace std;

// 3. ���Ǳ� �����ϱ� (while�� �̿��ؼ�)
//	- ������ �Է� �ޱ�
//	- ���� �������� �ܾ� ���� ǥ���Ͽ� ���
//	- �޴��� ���, 1.�ݶ�(100��) 2.���̴�(200��) 3.ȯŸ(300��) 4.��ȯ
//	- ���ÿ� ���� ���� �� �ܾ��� �ٲ�����
//	- �������� ������ �Ͽ� ���Ŵ� �Ұ����ϰ�, �ܾ��� �����մϴ� ���
//	- 4���� ������ �ܾ��� --���Դϴ�. ��� �� ���α׷��� �ѷ�.
int main()
{
	int iMoney = 0;
	int iSelect = 0;
	cout << "�ܾ��� �Է��� �ּ���!: ";
	cin >> iMoney;

	while (true)
	{
		cout << "�ܾ�: " << iMoney << endl << endl;
		system("pause");
		system("cls");

		cout << "===== �޴� =====" << endl;
		cout << "1.�ݶ�(100��)  2.���̴�(200��)  3.ȯŸ(300��)  4.��ȯ : ";
		cin >> iSelect;

		switch (iSelect)
		{
		case 1:
			if (iMoney - 100 < 0)
				cout << "�ܾ��� �����մϴ�!" << endl;
			else
			{
				iMoney -= 100;
				cout << "���ִ� �ݶ� ����ϴ�!" << endl;
			}
			break;
		case 2:
			if (iMoney - 200 < 0)
				cout << "�ܾ��� �����մϴ�!" << endl;
			else
			{
				iMoney -= 200;
				cout << "���ִ� ���̴ٸ� ����ϴ�!" << endl;
			}
			break;
		case 3:
			if (iMoney - 300 < 0)
				cout << "�ܾ��� �����մϴ�!" << endl;
			else
			{
				iMoney -= 300;
				cout << "���ִ� ȯŸ�� ����ϴ�!" << endl;
			}
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