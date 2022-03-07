#include <iostream>
using namespace std;

const int MAX_COUNT = 5;	// N명의 데이터 저장
const int MAX_LEN = 256;

struct StudentInfo
{
	char cName[MAX_LEN] = {};
	int iKor;
	int iEng;
	int iMath;
	int iTotal;
	float fAvg;
};

void InputInfo(StudentInfo* psuts, int* iCount)
{
	if (*iCount > MAX_COUNT - 1)
	{
		cout << "데이터 초과" << endl;
		system("pause");
		return;
	}

	cout << "이름: ";
	cin >> psuts[*iCount].cName;
	cout << "국어: ";
	cin >> psuts[*iCount].iKor;
	cout << "영어: ";
	cin >> psuts[*iCount].iEng;
	cout << "수학: ";
	cin >> psuts->iMath;
	
	psuts[*iCount].iTotal = psuts[*iCount].iKor + psuts[*iCount].iEng + psuts[*iCount].iMath;
	psuts[*iCount].fAvg = (float)psuts[*iCount].iTotal / 3;

	++(*iCount);
}
void PrintInfos(StudentInfo* psuts, int* iCount)
{
	system("cls");

	for (int i = 0; i < *iCount; i++)
	{
		cout << "이름: " << psuts[i].cName << "  " << "국어: " << psuts[i].iKor << "  " << "영어: " << psuts[i].iEng << "  " << "수학: " << psuts[i].iMath << "  " << "총점: " << psuts[i].iTotal << "  " << "평균: " << psuts[i].fAvg << endl;
	}

	system("pause");
}
void FindByNameAndPrintInfo(StudentInfo* psuts, int* iCount)
{
	system("cls");

	bool isFind = false;
	StudentInfo findedInfo = {};
	char cTemp[MAX_LEN] = {};
	cout << "찾으실 이름을 입력하세요. >> ";
	cin >> cTemp;
	for (int i = 0; i < *iCount; i++)
	{
		if (strcmp(psuts[i].cName, cTemp)) // 다르면
			continue;
		isFind = true;
		findedInfo = psuts[i];
	}

	if (isFind)
		cout << "이름: " << findedInfo.cName << "  " << "국어: " << findedInfo.iKor << "  " << "영어: " << findedInfo.iEng << "  " << "수학: " << findedInfo.iMath << "  " << "총점: " << findedInfo.iTotal << "  " << "평균: " << findedInfo.fAvg << endl;
	else
		cout << "찾으시는 정보는 없습니다..." << endl;

	system("pause");
}

void main()
{
	StudentInfo studentInfos[MAX_LEN] = {};
	void(*Funcs[3])(StudentInfo*, int*) = { InputInfo, PrintInfos, FindByNameAndPrintInfo };
	int iCount = 0;
	int iInput = 0;

	while (true)
	{
		system("cls");
		cout << "1.입력 2.전체 출력 3.검색 출력(이름) 4.종료 >> ";
		cin >> iInput;

		if (4 == iInput)
		{
			cout << "종료합니다." << endl;
			system("pause");
			return;
		}
		else if (4 < iInput)
		{
			cout << "다시 입력해 주세요." << endl;
			system("pause");
			continue;
		}

		Funcs[iInput-1](studentInfos, &iCount);
	}
}