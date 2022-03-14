#include<iostream>

using namespace std;

void main()
{
#pragma region 스트림

	// 스트림 : 장치들을 연결해 주는 가상의 통로, 보통 단 방향 스트림으로 입력 스트림, 출력 스트림으로 나뉜다.
	
	// printf, cout으로 문자 하나를 출력하는 것은 파리를 로켓으로 잡는 꼴 (부담스러운 작업임)

	// 입력 출력을 했다는 것은 스트림이 있다는 건데, cout cin은 자동으로 생성해줬다는 것
	//   ㄴ마찬가지로 임의로 스트림을 생성, 해제할 수도 있다!

	// 콘솔 표준 입출력 스트림
	{
		// stdin; 표준 입력 스트림     // 기본 키보드 대상
		// stdout; 표준 출력 스트림    // 기본 모니터 대상
		// stderr; 표준 에러 스트림    // 기본 모니터 대상이긴 하나 우리가 볼 수는 없다.
	}

	// window
	{
		// 하드웨어 소프트웨어를 총괄하는 최고 관리자

		// 다양한 프로그램에서 입력 출력 다수 발생 >> 메모장 입출력, 그림판 입출력, 게임 입출력 등등...
		// 일단 너무 많으니 입력을 큐에 넣어서 순서대로 처리
		// 식별번호를 매겨서 어떤 놈의 메시지인지 구별 필요 >> 핸들 사용 (아! 얘는 메모장에서 온 입력이구나!)
		//     ㄴ핸들 : 고유 식별 번호
	}

	// 스트림을 지정할 수 있는 함수는 곧, 핸들을 지정할 수 있는 함수를 의미하며, 핸들을 생성해주는 행동을 가리켜 '파일을 개방하다'라고 말하기도 한다.

#pragma endregion

#pragma region 버퍼

	// 버퍼 : 데이터를 임시 저장하기 위한 메모리 블록의 의미. 문자열 버퍼 > 문자를 저정하는 메모리 공간

	// 입력 버퍼, 출력 버퍼가 있다.
	// cpu는 많이 바쁘다(여러 프로그램 전부 작업중) >> 입력 들어오면 모아 놨따가 한번에 출력해서 보내줄게 >> 입력 버퍼, 출력 버퍼의 필요성


	// 입출력 모드 : 텍스트 모드, 바이너리 모드
	//   ㄴ앞으로 배울 모드는 텍스트 모드
	//      ㄴint형 변수 출력은 불가능 하다는 말.
	// 텍스트 모드 함수는 문자열만 지원, 바이너리 함수는 모든 자료형 또는 사용자 정의 자료형도 지원하는 함수


#pragma endregion

#pragma region 단일문자 입출력 함수

	// 단일 문자 출력 함수
	{
		// putchar, fputc
		putchar('A');     // stdout이란 출력 스트림을 기본값으로 사용

		fputc('A', stdout);   // 2인자는 어떤 스트림을 사용해서 출력할 꺼냐 선택 가능!

		// stdout은 핸들이 고정 >> 콘솔을 위한
		// 파일의 핸들을 사용하면 파일에 출력한다는 뜻이다!

	}


	// 단일 문자 입력 함수
	// getchar(), fgetc()
	{
		int ch = getchar();     // stdin이란 입력 스트림을 기본값으로 고정
		// 깜빡깜빡 프롬프트 >> 입력 버퍼가 대기 중이라는 말
		putchar(ch);

		int ch = fgetc(stdin);
		fputc(ch, stdout);
	}


	// EOF(EndOfFile) == -1
	{
		// 파일의 끝을 표현하기 위한 상수
		// 파일 입출력때 굉장히 중요하게 사용됨
	}

	// 입출력 함수의 반환 값이 존재하는 이유 : char는 시스템에 따라 unsigned가 될 수도 있다. >> EOF를 표현할 수 없다.
	// 그래서 반환 타입을 int타입으로 만들고 signed를 유지시켜 eof를 표현 할 수 있게 하려고 반환 값을 두었다.
	{
		while (true)
		{
			char ch = getchar();

			if (EOF == ch)    // ctrl + z키가 eof를 의미한다!
				break;

			putchar(ch);
		}
	}

#pragma endregion

#pragma region 문자열 입출력 함수

	// 문자열 출력
	{
		// puts, fputs   : 두 함수 모두 호출 성공 시 출력된 반환하고, 실패 시 EOF를 반환

		puts("Hello");			// 자동으로 개행이 적용
		fputs("HELLO", stdout);
	}

	// 문자열 입력 함수
	{
		// get_s, fgets
		char szInput[16] = "";
		gets_s(szInput, sizeof(szInput));    // 공백을 읽어들인다. 대신에 엔터는 읽을 수 없다.
		puts(szInput);						// 사이즈가 초과하면 메모리 오류를 발생


		fgets(szInput, sizeof(szInput), stdin);    // 엔터가 나올 때까지 읽는다. 설정한 사이즈만큼만 읽고 null을 고려
		fputs(szInput, stdout);
	}

#pragma endregion
}