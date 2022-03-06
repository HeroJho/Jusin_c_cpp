#include <iostream>
using namespace std;

const int MAX_SIZE = 5;
void MakeBoard(int(*pBoard)[MAX_SIZE])
{
	for (int i = 0; i < MAX_SIZE; i++)
		for (int j = 0; j < MAX_SIZE; j++)
			pBoard[i][j] = i * MAX_SIZE + j;
}
void PrintBoard(int(*pBoard)[MAX_SIZE])
{
	system("cls");
	for (int i = 0; i < MAX_SIZE; i++)
	{
		for (int j = 0; j < MAX_SIZE; j++)
			cout << pBoard[i][j] << "	";
		cout << endl;
	}
	system("pause");
}
bool MoveZero(int(*pBoard)[MAX_SIZE], int* pPos, int iInput)
{
	// �̵��� ��ǥ�� ���� ���Ѵ�.
	int x = 0, y = 0;
	
	switch (iInput)
	{
	case 8: y = pPos[1] - 1; break;
	case 2: y = pPos[1] + 1; break;
	case 4: x = pPos[0] - 1; break;
	case 6: x = pPos[0] + 1; break;
	}

	// ���� üũ
	if (x >= MAX_SIZE || y >= MAX_SIZE || x < 0 || y < 0)
		return false;

	// �迭 ����
	int temp = pBoard[y][x];
	pBoard[y][x] = pBoard[pPos[1]][pPos[0]];
	pBoard[pPos[1]][pPos[0]] = temp;
	
	pPos[0] = x;
	pPos[1] = y;

	return true;
}

void main()
{
	int iBoard[MAX_SIZE][MAX_SIZE] = { 0 };
	int iInput = 0;
	int iZeroPos[2] = { 0 };

	MakeBoard(iBoard);

	while (iInput != -1)
	{
		PrintBoard(iBoard);

		cout << "Ű�� �Է��ϼ���.(2-�� 4-�� 6-�� 8-��) >> ";
		cin >> iInput;
		if (!MoveZero(iBoard, iZeroPos, iInput))
			continue;

	}
}