#include <iostream>
using namespace std;

const int MAX_COUNT = 5;	// N명의 데이터 저장
#pragma region Tool

const int MAX_LEN = 100;
int GetLenth(char* c)
{
	int iLen = 0;
	for (iLen = 0; c[iLen] != '\0'; iLen++)
		iLen++;
	return iLen;
}
bool CheckSameName(float(*pArray)[MAX_LEN], char* iCmpVale, int iCount)
{
	bool isSame = false;
	int count = 0;
	system("cls");

	// 글자수 맞는지 체크
	if (GetLenth(iCmpVale) != pArray[0][0])
		return isSame;

	for (int j = 1; j <= pArray[0][0]; j++)
	{
		if (pArray[0][j] != iCmpVale[j - 1])
			break;
		count++;
		if (count == pArray[0][0])
			isSame = true;
	}

	return isSame;
}
bool CheckAllSameName(float((*pArray)[2])[MAX_LEN], char* iCmpVale, int iCount)
{
	bool isSame = false;

	for (int i = 0; i < iCount; i++)
	{
		if (CheckSameName(pArray[i], iCmpVale, iCount))
			return true;
	}
	return false;
}
void PrintInfo(float(*pArray)[MAX_LEN])
{
	cout << "이름: ";
	for (int j = 1; j <= pArray[0][0] + 1; j++)
		cout << (char)pArray[0][j];
	cout << " " << "국어:" << pArray[1][0] << " 영어:" << pArray[1][1] << " 수학:" << pArray[1][2] << " 총점:" << pArray[1][3] << " 평균:" << pArray[1][4] << endl << endl;
}

#pragma endregion

#pragma region Func

bool InputInfo(float((*pArray)[2])[MAX_LEN], int iCount)
{
	system("cls");

	int iLen = 0;
	char cName[MAX_LEN] = {};

	cout << endl;
	cout << "이름: ";
	cin >> cName;

	if (CheckAllSameName(pArray, cName, iCount))
		return false;

	iLen = GetLenth(cName);
	for (int j = 0; j <= iLen; j++)
	{
		if (j == 0)
			pArray[iCount][0][j] = iLen;
		else
			pArray[iCount][0][j] = cName[j - 1];
	}

	cout << "국어: ";
	cin >> pArray[iCount][1][0];
	cout << "영어: ";
	cin >> pArray[iCount][1][1];
	cout << "수학: ";
	cin >> pArray[iCount][1][2];
	pArray[iCount][1][3] = pArray[iCount][1][0] + pArray[iCount][1][1] + pArray[iCount][1][2];
	pArray[iCount][1][4] = pArray[iCount][1][3] / 3;

	return true;
}
void PrintInfos(float((*pArray)[2])[MAX_LEN], int iCount)
{
	cout << endl;
	system("cls");

	for (int i = 0; i < iCount; i++)
		PrintInfo(pArray[i]);

	system("pause");
}
void FindByNameAndPrintInfo(float((*pArray)[2])[MAX_LEN], int iCount)
{
	char cName[MAX_LEN] = {};
	bool isSame = false;

	cout << endl;
	cout << "이름: ";
	cin >> cName;

	system("cls");
	for (int i = 0; i < iCount; i++)
	{
		if (CheckSameName(pArray[i], cName, iCount))
		{
			PrintInfo(pArray[i]);
			system("pause");
			return;
		}
	}
	cout << "정보가 없습니다.." << endl;;
	system("pause");
	return;
}

#pragma endregion

void main()
{
	float iArray[MAX_COUNT][2][MAX_LEN] = {};
	int iCount = 0;
	int iInput = 0;

	while (true)
	{
		system("cls");
		cout << "1.입력 2.전체 출력 3.검색 출력(이름) 4.종료 >> ";
		cin >> iInput;
		switch (iInput)
		{
		case 1:
			if (iCount > MAX_COUNT - 1)
			{
				cout << "더이상 데이터를 저장할 수 없습니다." << endl;
				system("pause");
			}
			else if (!InputInfo(iArray, iCount))
			{
				cout << "이름이 중복됩니다. 개명하십쇼." << endl;
				system("pause");
			}
			else
				iCount++;
			break;
		case 2:
			PrintInfos(iArray, iCount);
			break;
		case 3:
			FindByNameAndPrintInfo(iArray, iCount);
			break;
		case 4:
			cout << "종료합니다." << endl;
			system("pause");
			return;
		default:
			cout << "다시 입력해 주세요." << endl;
			system("pause");
			break;
		}
	}
}