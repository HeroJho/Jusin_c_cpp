#include <iostream>
#include <time.h>
using namespace std;

#pragma region AI_TEMP_MEMORY
int itemplyMemory[25] = { 0 };
int iLevel = 0;
void setLevel()
{
	int iInput = 0;
	cout << "Ai의 난이도를 선택해 주세요! (1~4 단계) >> ";
	cin >> iInput;

	switch (iInput)
	{
	case 1:
		iLevel = 5;
		break;
	case 2:
		iLevel = 10;
		break;
	case 3:
		iLevel = 20;
		break;
	case 4:
		iLevel = 24;
		break;
	}
}
bool templyMemory(int iValue)
{
	for (int i = 0; i < iLevel; i++)
	{
		if (itemplyMemory[i] == iValue)
			return false;
	}
	for (int i = 0; i < iLevel; i++)
	{
		itemplyMemory[i] = itemplyMemory[i + 1];
	}
	itemplyMemory[iLevel] = iValue;
	return true;
}
#pragma endregion

const int BOARD_SIZE = 5;
#pragma region Func

void MakeBingoBoard(int(*pArray)[BOARD_SIZE])
{
	int iA = 0, iB = 0, iTemp = 0;
	int iRandArray[BOARD_SIZE* BOARD_SIZE] = { 0 };

	for (int i = 0; i < BOARD_SIZE* BOARD_SIZE; i++)
	{
		iRandArray[i] = i + 1;
	}

	for (int i = 0; i < 100* BOARD_SIZE; i++)
	{
		iA = rand() % (BOARD_SIZE* BOARD_SIZE);
		iB = rand() % (BOARD_SIZE* BOARD_SIZE);

		iTemp = iRandArray[iA];
		iRandArray[iA] = iRandArray[iB];
		iRandArray[iB] = iTemp;
	}

	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			pArray[i][j] = iRandArray[i* BOARD_SIZE + j];
		}
	}

}
void ShowBingoBoard(int(*pPlayerArray)[BOARD_SIZE], int(*pComputerArray)[BOARD_SIZE])
{
	system("cls");
	cout << "========== 나의 빙고판 ==========" << endl;
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			if (pPlayerArray[i][j] == -1)
				cout << "*	";
			else
				cout << pPlayerArray[i][j] << "	";
		}
		cout << endl;
	}
	cout << endl;
	cout << "========== AI의 빙고판 ==========" << endl;
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			if (pComputerArray[i][j] == -1)
				cout << "*	";
			else
			{
				//cout << pPlayerArray[i][j] << "	";
				cout << "0" << "	";
			}
		}
		cout << endl;
	}
}
void ShowBingoEffect()
{
	system("cls");

	cout << "                                              " << endl;
	cout << " 0             0    0                   00    " << endl;
	cout << " 0             0    0    0000000000     00    " << endl;
	cout << " 000000000000000    0             0     00    " << endl;
	cout << " 0             0    0             0     00    " << endl;
	cout << " 0             0    0             0     00    " << endl;
	cout << " 000000000000000    0             0     00    " << endl;
	cout << "                              0         00    " << endl;
	cout << "   0000000000000              0         00    " << endl;
	cout << "  0             0             0               " << endl;
	cout << "  0             0             0         00    " << endl;
	cout << "   0000000000000         00000000000    00    " << endl;
	cout << "                                              " << endl;

	system("pause");
}

void TryBingo(int(*pArray)[BOARD_SIZE], int iValue)
{
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			if (pArray[i][j] == iValue)
				pArray[i][j] = -1;
		}
	}
}
void ChackBingo(int(*pArray)[BOARD_SIZE], int* iBingo)
{
	int iTemp = 0, iB = 0;
	// 세로 확인
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			if (pArray[i][j] == -1)
				iTemp++;
		}
		if (iTemp == BOARD_SIZE)
			iB++;
		iTemp = 0;
	}
	// 가로 확인
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			if (pArray[j][i] == -1)
				iTemp++;
		}
		if (iTemp == BOARD_SIZE)
			iB++;
		iTemp = 0;
	}
	// 대각선 확인(중간 좌표만)
	{
		for (int i = 0; i < BOARD_SIZE; i++)
		{
			if (pArray[i][i] == -1)
				iTemp++;
		}
		if (iTemp == BOARD_SIZE)
			iB++;
		iTemp = 0;
	}
	{
		for (int i = 0, j = BOARD_SIZE-1; i < BOARD_SIZE; i++, j--)
		{
			if (pArray[i][j] == -1)
				iTemp++;
		}
		if (iTemp == BOARD_SIZE)
			iB++;
		iTemp = 0;
	}

	if (iB - *iBingo > 0)
		ShowBingoEffect();
	*iBingo = iB;
}

void TurnComputer(int(*pArray)[BOARD_SIZE], int* iBingo)
{
	int iRanNum = 0;

	do
	{
		iRanNum = rand() % (BOARD_SIZE* BOARD_SIZE) + 1;
	} while (!templyMemory(iRanNum));

	TryBingo(pArray, iRanNum);
	ChackBingo(pArray, iBingo);
}
void TurnPlayer(int(*pArray)[BOARD_SIZE], int* iBingo)
{
	int iInput = 0;
	cout << "빙고를 입력하세요! >> ";
	cin >> iInput;

	TryBingo(pArray, iInput);
	ChackBingo(pArray, iBingo);
}

#pragma endregion

void main()
{
	int iPlayerBingoBoard[BOARD_SIZE][BOARD_SIZE] = {0};
	int iComputerBingoBoard[BOARD_SIZE][BOARD_SIZE] = {0};
	int iInput = 0, iPlayerBingo = 0, iComputerBingo = 0;

	srand(unsigned(time(NULL)));

	MakeBingoBoard(iPlayerBingoBoard);			// 보드 만들기
	MakeBingoBoard(iComputerBingoBoard);

	setLevel();									// 레벨 설정

	while (true)
	{
		ShowBingoBoard(iPlayerBingoBoard, iComputerBingoBoard);

		TurnPlayer(iComputerBingoBoard, &iPlayerBingo);
		if (iPlayerBingo >= 5)
			break;
		TurnComputer(iPlayerBingoBoard, &iComputerBingo);
		if (iComputerBingo >= 5)
			break;

		ShowBingoBoard(iPlayerBingoBoard, iComputerBingoBoard);
		cout << "나의 빙고: " << iPlayerBingo << "	Ai의 빙고: " << iComputerBingo << endl;

		system("pause");
	}
	
	system("cls");
	if (iPlayerBingo >= 5)
		cout << "나의 승리!!!" << endl;
	else
		cout << "Ai한테 지니..." << endl;

}