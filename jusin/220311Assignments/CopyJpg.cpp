#include <iostream>

using namespace std;

#define K 1000
#define M K*1000

void main()
{
    char* temp = new char[7 * M];

    FILE* pFile = nullptr;
    errno_t err = fopen_s(&pFile, "../Data/Image.jpg", "rb");  // ��� ��� vcx �� ĭ �ڷ�
    if (0 == err)
    {
        fread(temp, sizeof(char), 7 * M, pFile);

        fclose(pFile);

        cout << "�ҷ����� ����!" << endl;
    }
    else {
        cout << "�ҷ����� ����!" << endl;
    }

    pFile = nullptr;
    err = fopen_s(&pFile, "../Data/Copy.jpg", "wb");  // ��� ��� vcx �� ĭ �ڷ�
    if (0 == err)
    {

        fwrite(temp, sizeof(char), 7 * M, pFile);

        fclose(pFile);

        cout << "���� ����!" << endl;
    }
    else {
        cout << "���� ����!" << endl;
    }
}