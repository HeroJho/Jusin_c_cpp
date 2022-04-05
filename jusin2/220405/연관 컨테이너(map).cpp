#include "pch.h"

#pragma region STL의 연관 컨테이너 (비선형)

//	-균현 이진 탐색 트리를 사용.
//	-탐색을 위한 자료구조.
//	-map컨테이너는 중위순회를 통해 순회.
// 이진 트리를 탐색하기 위한 방법
//	-전위, 중위, 후위순회와 레벨 순회

#pragma endregion


#pragma region map

// -균형 이진 탐색 트리이다.
// -한 노드는 key와 value를 가진다.
//	 ㄴpair라는 객체로 두 개의 자료를 관리한다
//   ㄴkey는 중복될 수 없다!
// -키값으로 정렬하고, 비교하며 탐색한다.
// -삽입 삭제를 할 때 자동으로 균형을 이루기 위해 재정렬을 한다. (레드 블랙으로 구현)
//   ㄴ재정렬을 해서 삽입 삭제 비용이 비싸다
//   ㄴ삽입 삭제 잦으면 x
// -탐색의 용이하다.
//   ㄴ이진 탐색 트리(longN)!!
// -인덱스 연산자가 오버로딩이 되어 있어서 유일하게 임의접근(인척)할 수 있다.

#pragma endregion

#pragma region multi_map

// multi_map
// map과 같고 키 값 중복이 허용된다.
// 인덱스 연산자가 오버로딩 X
// 일반적으로 잘 안 쓰인다!

#pragma endregion

#pragma region set

// -키값만 가진다.
//		ㄴ키값 기준으로 정렬한다.
//		ㄴ중복 키값을 허용하지 않는다.
// -보통 정렬을 하고싶을때 set에 넣어 꺼내서 사용한다.
// 사용할 일이 없다 (map이 용이)!

#pragma endregion

#pragma region multi_set

// multi_set
// set과 같고, 중복 키를 허용한다

#pragma endregion
