﻿#include "pch.h"

#pragma region STL이란?

//  - 표준 템플릿 라이브러리
//  - 클래스 템플릿을 모아놓은 집합
//	- c++에서 제공하는 라이브러리의 일종으로 프로그래밍에 필요한 자료구조 및 알고리즘을 제공
//  - 템플릿을 기반이기 때문에 모든 자료형에 호환하므로 일반화 프로그래밍의 한 예로 말할 수 있다.

// 왜 이런걸 만들었어?
//  ㄴ 어차피 자료구조, 알고리즘은 개념은 같다. 이걸 표준화해서 코드의 난잡함(니 리스트는 이거, 내 리스트는 이거)을 방지
//  ㄴ 많은 데이터를 잘 다루는 능력은 프로그래머의 능력! 잘 숙지해서 적절한 상황에 사용할 줄 알아야 한다!

// STL의 구성요소
//  1.컨테이너
//  2.알고리즘
//  3.함수객체
//  4.반복자(이터레이터) *중요

#pragma endregion


#pragma region 컨테이너(중요!)

//	정의
//	- 데이터를 저장하는 객체, 또는 자료 구조가 구현되어 있는 객체
//	종류
//	- vector, deque, list, set, multiset, map, multimap, string


// 컨테이너 구분 기준
//	1.원소를 어떻게 배치하느냐
//	2.메모리를 어떤 형식으로 생성하느냐

#pragma region 원소 배치에 따른 종류(중요!)

// 1. 표준 시퀀스 컨테이너
//  선형적
//	시퀀스: 가지런히 놓여져 있는 형태
//  데이터가 시퀀스로 나열
//	vector, deque, list
// 2. 표준 연관 컨테이너
//	비선형적
//  ex) 트리 구조
//  set, multiset, map, multimap

#pragma endregion

#pragma region 메모리 저장 방식에 따른 분류(중요!)

// 메모리 저장 방식에 따른 분류
// 1. 배열 기반 컨테이너
// vector, deque
// 2. 노드 기반 컨테이너
// list,set,multiset,map,multimap

#pragma endregion

#pragma region 추가 분류(안 중요)

// 컨테이너 어댑터
//  기존 컨테이너에 기능 중 일부 기능만을 사용 가능하여, 기능 제한이나 기능이 변형되어 있는 컨테이너를 말한다.
//  queue, stack, prioityQueue

// 근사(almost) 컨테이너
//	string, wstring
//	string은 템플릿이지만 특수화가 이뤄진 컨테이너

#pragma endregion


#pragma endregion


#pragma region STL 알고리즘

// - 컨테이너 내에서 정렬, 삭제, 탐색 등을 해결하는 일반화된 방법을 제공하는 함수 템플릿 모음
// - 대부분의 알고리즘 함수 템플릿은 특정 컨테이너의 멤버가 아닌 전역의 형태로 작성되어 있다.
// - 객체에 멤버로 포함하여 캡슐화를 적극적으로 사용하지 않은 이유는 일반화 프로그래밍에서 다수 컨테이너에 대해 보편적으로 적용할 수 있도록 하기 위함이다.
// - 알고리즘 함수 템플릿의 대부분은 <algorithm> 헤더 파일에 존재한다.


// 알고리즘 공부해야하나?
//		학원을 졸업해서 알고리즘 공부? 해야한다! 하지만!
//		취업에서 보면 투자대비 아웃풋이 적은 편이다.
//		신입한테는 어려운 알고리즘을 요구하지 않는다!
//		자료구조 >> C# or 시스템 프로그래밍 >> 알고리즘 순으로 중요하다.(투자대비 아웃풋 많은 순)
//		그냥 자료구조를 딥 하게 파자!!


#pragma endregion


#pragma region 함수 객체

// - operator를 오버로딩 해놓은 클래스들을 포함하고 있다. 
// - 컴파일 시 알고리즘의 인자값의 형태로 함수 객체를 전달할 수 있다.
// - 함수 객체는 호출 라인을 인라인화하여 일반 함수 호출보다 빠르다.

#pragma endregion


#pragma region 반복자(중요!)

// - 컨테이너 내의 원소를 순회하여 접근 또는 값 변경을 하기 위한 '객체'
// - STL의 핵심이며, 컨테이너마다 데이터 저장 방식 및 메모리 구조가 다르기 때문에 각각 순회방법을 일반화하기 위해 사용!
// - 컨테이너 마다 반복자 객체를 템플릿화하여 만들어 놓았고, 반복자끼리 대입, 비교 연산 등 여러 연산자들 또한 오버로딩이 되어있다.

#pragma endregion


// + 빅오표기법 , 상수 시간, 로그 시간, 선형 시간, 지수 시간 이해, 암기!!


// 면접 단골 질문!
#pragma region vector vs list

#pragma region vector

// 1. 동적 배열을 기반으로 하는 컨테이너이다.
// 2. 배열기반이기 때문에 임의 접근(인덱스 접근)이 가능하다.
//		ㄴ탐색 용이! (상수 시간)
// 3. 삽입 시, 맨 끝에서부터 삽입한다.
//      ㄴ끝 삽입 용이! (상수 시간)
// 4. 중간 삽입 및 삭제 시, 공간 확보, 활용을 위해 인덱스 이후의 원소를 전부 이동해야한다.
//		ㄴ중간 삽입 삭제 불리! (선형 시간)
// 5. 배열의 크기를 넘어가는 삽입이 발생할 시, 동적 배열의 재 할당 및 현재 원소들의 복사가 일어나기 때문에 느리다.

// 벡터의 수학에서의 표현
// 반계 구간 : 반만 열려있다. ')' 열려있다
// [begin, end) 

#pragma endregion


#pragma region list

// 1. 노드를 기반으로 하는 컨테이너이다.
// 2. 더블 링크드 리스트로 구현된 컨테이너.
// 3. 배열과 달리 노드는 비 연속적인 메모리 공간.
//			ㄴ 각 노드에 대한 임의 접근(인덱스 접근)이 불가능
//			ㄴ 헤더부터 하나씩 탐색해야한다.
//			ㄴ 탐색 불리! (선형)
// 4. 중간 삽입 및 삭제가 용이!
//			ㄴ 포인터를 통해 노드의 앞, 뒤를 연결 및 연결 해제!
//			ㄴ 삽입 삭제 용이! (상수)
// 5. 배열과 달리 사용자가 원하는 만큼 런타임 시에도 계속해서 노드를 추가해 데이터 저장에 용이.

#pragma endregion



#pragma region 결론

// 탐색이 중요하다! >> 벡터
// 중간 삽입 삭제가 많다! >> 리스트

#pragma endregion


#pragma endregion
