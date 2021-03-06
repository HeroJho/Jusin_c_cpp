#include <iostream>
using namespace std;

int main()
{
    // 버퍼 함수 : 버퍼를 비우기 위한 용도의 함수
    {
        // '비우다'는 삭제의 의미가 아니라 버퍼 공간에서 목적지까지 강제로 이동시키는 것을 의미.
        // 출력 버퍼만 비울 수 있다. 입력 버퍼는 불가능.
        // 심지어 출력 버퍼를 비우는 일도 거의 안 한다. 함수가 있는 정도만 알기!
        // fflush(stdout);  출력 버퍼 비우기 함수
    }
    // 입력 버퍼를 비워야 하는 이유
    {
        char szID[8] = "";
        char szName[16] = "";

        fgets(szID, sizeof(szID), stdin);  // 길게 치면 입력 버퍼를 넘어서 쓴다

        while ('\n' != getchar());

        fgets(szName, sizeof(szName), stdin);

        fputs(szID, stdout);
        fputs(szName, stdout);
        // fgets같은 함수는 텍스트 모드만 지원, >> c++넘어가서는 API입출력으로 클래스 등등을 나타냄으로 지금 배우는 건 안씀
    }


    // 텍스트 모드 파일 입출력 함수
    {
        // 콘솔 입출력의 경우 스트림(핸들) 생성, 소멸을 운영체제가 알아서 진행해준다. 스트림 자체가 시스템의 자원이기 때문에 가능.
        // 파일 입출력의 경우 핸들을 직접 생성, 소멸 해야하기 때문에 이와 관련된 함수들을 알아야 할 필요가 있다.

        // 바이너리 모드 하는 이유 : 여러 자료형을 저장 또는 불러오기 하기위해 사용한다. 텍스트 모드보다 속도가 월등히 빠르고, 용량도 훨씬 작다

        // 로딩 개념 2가지
        // 한번에 전부 가져와서 읽는 방법
        // 스트리밍은 조금씩 분할해서 읽어들이는 방법  >> 지속적으로 읽어들이기 때문에 지속적으로 갱신 돼야한다.
        // 필요할 때 적재적소에 사용하는게 스트리밍 방식

        // 파일을 불러오고 적으려면 경로가 필요하다
        // 절대 경로: 드라이브 명부터 현재 폴더 까지
        // 상대 경로: vcs 기준 경로 (상대적으로 안전)


        // 스트림을 생성해주는 함수
        // 다음 순서는 다른 언어에서 모든 관통하는 순서이다.
        // 개방 -> 쓰기, 읽기 -> 소멸
        // 순서
        // 1) fopen_s   스트림 생성 함수(파일 개방 함수)
        // 2) 쓰기 전용, 읽기 전용
        // 3) fclose    스트림 소멸 함수(파일 소멸 함수)


        // 원형 fopen_s(, )
        // 1인자: output 인자, 2인자: 파일에 있는 위치까지의 경로와 파일명, 3인자: 모드를 설정(자료 찾아서 보기)
        //      ㄴ모드1 r, w, a, r+, w+, a+
        //      ㄴr, w을 주로 쓴다. 프로그래밍은 한 번에 한 번의 작업만 하도록 하는게 좋다. 코드도 논리적연하게 작성 가능해 진다.
        //      ㄴ모드2 : t b      대부분의 데이터는 바이너리 모드이다. >> 텍스트 모드보다 속도가 월등히 빠르고, 용량도 훨씬 작다
        // 총 12개의 모드를 만들 수 있다.

        // 제대로 개방이 됐냐 안됐냐 반환값  >> 성공 0 실패 0아닌 값


        // 텍스트 모드 파일 출력
        {

            FILE* pFile = nullptr;
            errno_t err = fopen_s(&pFile, "../Data/Test.txt", "wt");  // 상대 경로 vcx 한 칸 뒤로

            if (0 == err)
            {
                // 성공

                fputs("world", pFile);

                fclose(pFile);
            }
            else {
                // 실패
            }
        }
        // 텍스트 모드 파일 입력
        {

            FILE* pFile = nullptr;
            errno_t err = fopen_s(&pFile, "../Data/Test.txt", "rt");

            char szBuf[32] = "";

            if (0 == err)
            {
                // 성공

                fgets(szBuf, sizeof(szBuf), pFile);   // 파일 입력
                fputs(szBuf, stdout);    // 콘솔 출력

                fclose(pFile);
            }
            else {
                // 실패
            }
        }
    }


    // 저장할 때 NULL도 저장이 되나?
    {
        // 파일 입력
        FILE* pFile = nullptr;
        errno_t err = fopen_s(&pFile, "../Data/Test.txt", "wt");

        char szBuf[32] = "Hello";

        if (0 == err)
        {
            // 성공
            fputs(szBuf, pFile);    // 콘솔 출력

            fclose(pFile);    // 일단은 Hello만 메모장에 있음

            // 파일 입출력에서 문자열의 끝은 null문자로 판단하는 것이 아니라 eof를 통해서 판단할 수 있다.
            // 다시 쓴 걸 읽어오면 NULL이 없다
            // 즉, 다시 불러올 때 eof로 인식한다.
        }
        else {
            // 실패
        }
    }


    // 개행 후 땡기는 행위
    {
        cout << "hello" << endl;   // cout 자체가 stdout 기반이니 텍스트 모드
        cout << "world" << endl;   // 텍스트 모드에서는 \r 개행하고 앞으로 땡기는게 자동으로 삽입 되어있음

        // 바이너리의 경우 없음!! >> 바이너리의 경우 땡겨버리면 큰일 남!!

        // c언어에서 텍스트 모드 출력 시 \n은 운영체제마다 다른 기능을 갖게 된다.
        // 윈도우 : \r\n (carriage return 기본 제공) >> 단 바이너리 모드에서는 해당 X
        // 유닉스 : \n
        // Mac    : \r
    }


    // 지원하는 파일 함수
    {
        // fseek : 개방한 파일을 원하는 바이트 수만큼 이동시키는 함수
        // 1인자: 개방한 스트림, 2인자 :바이트 수 3인자 : 옵션 SEEK_SET 처음부터 SEEK_CUR 현재 프롬프트 위치부터 SEEK_END 파일의 끝 부터
        // feof(스트림) :  파일의 끝 유무를 알려주는 함수
        // ftell(스트림) : 현재 프롬프트의 위치를 알려주는 함수
    }


    // 입출력이 잦으면 생기는 문제점들
    {
        // 여러 프로세스가 돌아가는 건 동시에 돌아가는 것 처럼 보이는 것 뿐
        // 실제로는 빠르게 왓다갓다
        // cpu의 레지스터에 프로그램의 명령어들을 저장
        // 변경될 때 명령어들을 버리거나 따로 저장 >> 부담 스러운 작업

        // 입출력 연산할 때 마다 프로세스간의 전환이 일어남 >> 전체적인 속도가 느려짐 >> 최소한 입출력을 해야한다.
        // 그래서 로딩창이 생긴거임 >> 입출력 최소화 너무 많이 불러오지도 않고 적게 불러와서 입출력 자주하는거 방지

        // 게임은 출력을 안하면 속도가 빠르고, 출력을 하면 느려진다 > 최적화의 제 1원칙
        // 그래서 프로그래머는 언제 입출력을 할건지 정하는 능력이 필요
    }

    

    // 바이너리 모드 파일 입출력
    {
        // size_t fwrite(const void* pBuffer, size_t Size, size_t COunt, FILE* strea);
        // fwrite(배열이름, 배열사이즈, 1, 파일)
        // fwrite(배열이름, 자료형 사이즈, 배열 사이즈, 파일)
        
        // 읽기
        // size_t fread(const void* pBuffer, size_t Size, size_t COunt, FILE* strea);
        // fread(배열이름, 사이즈, 갯수, 스트림)
    }
}



// 1. 플레이어의 데이터를 저장하고 불러와라
// 2. 이미지 파일을 똑같이 복사해보기