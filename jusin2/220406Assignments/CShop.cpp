#include "pch.h"
#include "CShop.h"
#include "CGameManager.h"

CShop::CShop()
{
}
CShop::~CShop()
{
}

void CShop::Update()
{
	int iInput = 0;

	do
	{
		cout << "������ ����?" << endl;
		cout << "1.��  2.����  3.�ڷΰ���	>> ";
		cin >> iInput;

		if (1 > iInput || 3 < iInput)
		{
			cout << "�ٽ� �Է��� �ּ���!" << endl;
			system("pause");
			continue;
		}

		break;
	} while (true);


	switch (iInput)
	{
	case 1:
	case 2:
	{
		CItem item(iInput);
		CGameManager::Get_Player()->GetItemToInven(item);
		cout << "���� �Ϸ�!" << endl;
		system("pause");
	}
	break;
	case 3:
		break;
	}

	CGameManager::Set_CurField(CGameManager::Get_PreField());
}

