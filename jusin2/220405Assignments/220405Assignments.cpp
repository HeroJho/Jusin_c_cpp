#include "pch.h"

// 숙제
// 벡터를 이용해서 성적표 만들기
// 입력 전체출력 검색출력 삭제
// erase() >> 삭제함수 >> 이터레이터를 통해서 사용해야함

#include "StudentsMgr.h"

int main()
{
	StudentsMgr s;

	int iInput = 0;
	do
	{
		system("cls");

		cout << "1.입력  2.출력  3.찾기  4.삭제  5.종료" << endl;
		cin >> iInput;

		switch (iInput)
		{
		case 1:
			s.CreateData();
			break;
		case 2:
			s.PrintAll();
			break;
		case 3:
			s.FindAndPrint();
			break;
		case 4:
			s.Remove();
			break;
		case 5:
			return 0;
		default:
			cout << "다시 입력해 주세요" << endl;
			system("pause");
			break;
		}

	} while (true);

	return 0;
}
