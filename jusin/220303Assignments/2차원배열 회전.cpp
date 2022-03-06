#include <iostream>
using namespace std;

const int MAX_ARRAY_SIZE = 3;
void angle_90(int(*pArray)[MAX_ARRAY_SIZE])
{
    int iTemp[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE] = { 0 };

    for (int i = 0; i < MAX_ARRAY_SIZE; i++)
        for (int j = 0; j < MAX_ARRAY_SIZE; j++)
            iTemp[j][(MAX_ARRAY_SIZE - 1) - i] = pArray[i][j];

    for (int i = 0; i < MAX_ARRAY_SIZE; i++)
        for (int j = 0; j < MAX_ARRAY_SIZE; j++)
            pArray[i][j] = iTemp[i][j];
}
void makeArray(int(*pArray)[MAX_ARRAY_SIZE])
{
    for (int i = 0; i < MAX_ARRAY_SIZE; i++)
        for (int j = 0; j < MAX_ARRAY_SIZE; j++)
            pArray[i][j] = i * MAX_ARRAY_SIZE + j;
}
void printArray(int(*pArray)[MAX_ARRAY_SIZE])
{
    for (int i = 0; i < MAX_ARRAY_SIZE; i++)
    {
        for (int j = 0; j < MAX_ARRAY_SIZE; j++)
        {
            if (pArray[i][j] < 10)
                cout << " ";
            cout << pArray[i][j] << "   ";
        }
        cout << endl;
    }
    cout << endl;
}

int main()
{
    int iArray[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE] = { 0 };

    makeArray(iArray);
    printArray(iArray);

    angle_90(iArray);
    printArray(iArray);

    angle_90(iArray);
    printArray(iArray);

    angle_90(iArray);
    printArray(iArray);

    angle_90(iArray);
    printArray(iArray);

}