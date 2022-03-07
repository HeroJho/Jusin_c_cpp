#include <iostream>

using namespace std;

int main()
{
	// 문자열 역사
	// SBCS(싱글바이트) -> MBCS(멀티바이트) -> WBCS로 발전
	// 영어로는 모든 언어 표기x >> MBCS
	// 영어1바이트 한글 2바이트... 혼동의 여지 >> 다 2바이트로 통일하자 >> WBCS

#pragma region 문자열 관련 함수

	// 문자열 길이 반환 함수
	// strlen()
	// size_t == unsigned int 음수x
	char szName[64] = "hello";
	cout << strlen(szName) << endl; // NULL문자를 제외한 순수한 문자열을 반환

	// 문자열 복사 함수
	char szTemp[64] = "";
	// csTemp = "hello";  문자열 대입은 불가능
	// 1인자 : 어디에 복사할 것인가
	// 2인자 : 얼마만큼의 크기 공간에 복사할 것인가
	// 3인자 : 복사하고자하는 원본 문자열
	char cc[64] = "sssssss";
	strcpy_s(szTemp, sizeof(szTemp), "Hello");   //error_t == int 옛날에는 bool이 없었따
	strcpy_s(szTemp, sizeof(szTemp), cc);
	// 복사하는 곳 공간이 널널하게

	// 문자열 결합 함수
	// 1인자 : 어디에 결합할 것인가
	// 2인자 : 얼마만큼의 크기 공간에 결합할 것인가
	// 3인자 : 결합하고자하는 원본 문자열
	char szSour[64] = "hello";
	char szTemp[64] = "world";
	strcat_s(szSour, sizeof(szSour), szTemp);
	
	// 문자열 비교 함수
	// 인자값 두개를 비교하여 일치 0 불일치 1반환
	strcmp(szSour, szTemp);

	// 문자열 함수는 되게 많다! 필요할 때마다 찾아서 사용하자.

#pragma endregion

}