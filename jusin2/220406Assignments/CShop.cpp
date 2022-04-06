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
		cout << "무엇을 살까요?" << endl;
		cout << "1.검  2.방패  3.뒤로가기	>> ";
		cin >> iInput;

		if (1 > iInput || 3 < iInput)
		{
			cout << "다시 입력해 주세요!" << endl;
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
		cout << "구매 완료!" << endl;
		system("pause");
	}
	break;
	case 3:
		break;
	}

	CGameManager::Set_CurField(CGameManager::Get_PreField());
}

