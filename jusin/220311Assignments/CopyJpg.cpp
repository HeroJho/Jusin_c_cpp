#include <iostream>

using namespace std;

#define K 1000
#define M K*1000

void main()
{
    char* temp = new char[7 * M];

    FILE* pFile = nullptr;
    errno_t err = fopen_s(&pFile, "../Data/Image.jpg", "rb");  // 상대 경로 vcx 한 칸 뒤로
    if (0 == err)
    {
        fread(temp, sizeof(char), 7 * M, pFile);

        fclose(pFile);

        cout << "불러오기 성공!" << endl;
    }
    else {
        cout << "불러오기 실패!" << endl;
    }

    pFile = nullptr;
    err = fopen_s(&pFile, "../Data/Copy.jpg", "wb");  // 상대 경로 vcx 한 칸 뒤로
    if (0 == err)
    {

        fwrite(temp, sizeof(char), 7 * M, pFile);

        fclose(pFile);

        cout << "복사 성공!" << endl;
    }
    else {
        cout << "복사 실패!" << endl;
    }
}