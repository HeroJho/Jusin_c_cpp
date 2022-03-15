﻿#include <iostream>

// 헤더 파일의 두 종류
// include ""   사용자 정의   // 프로그램이 있는
// include <>   비주얼 스튜디오가 설치된 경로에서 가져옴

// 헤더파일은 메뉴판 같은 것
// 코드는 선언부와 정의부로 나눠서 사용한다.
// 헤더파일은 선언부(메뉴), cpp는 구체적인 구현(핵심 기술) > 암호화해야 한다.
// 헤더는 제공하는 것, cpp는 숨겨야하는 것

// stdafx.h(프리 컴파일)  : 자주 사용하지만 자주 변경되지 않는 표준 시스템 포함 파일 또는
// 프로젝트 관련 포함 파일이 들어 있는 포함 파일 ex) iostream
//   ㄴ프리 컴파일 -> include하는걸 매 파일에서 반복적인 불러오는 작업을 없애기 위해서

// #pragma once  -> 헤더파일의 중복 포함을 피하기 위한 전처리기 문법이다.
//   ㄴ c++에서 생긴 문법
// c때는 어떻게 했는데?
#ifndef     _TEST

#define _TEST

// 헤더 선언

#endif


int main()
{
    
}
