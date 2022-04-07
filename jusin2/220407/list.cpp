#include <iostream>

// list 헤더!
#include <list>
using namespace std;

int main()
{

// 설명할 줄 알 정도로 이해, 암기하기!!!

#pragma region list란

	// 리스트
	// 선형 구조.
	// 노드 기반의 컨테이너.

	list<int>	ilstInt;
	
#pragma endregion

#pragma region vector와 list 차이점

	// 배열기반 vs 노드기반
	//   ㄴ배열: 반복자가 임의접근까지 사용
	//   ㄴ노드: 양방향 반복자까지 사용

	// 중간 삽입 삭제 이점
	//   ㄴvector: 중간 삽입 삭제시 원소의 이동이 많음
	//   ㄴlist : 중간 삽입 삭제시 포인터만 변경하면 끝(원소 이동 x)

#pragma endregion

#pragma region 함수

	// push_back()
	// pop_back()
	// 순회할 때 [], iter += 3을 통해 하지 못 한다.
	// 반복자를 통해서 ++, -- 하여 가능!

	// push_front()
	// pop_front()

	// 리스트 또한 size, clear, empty, swap, erase 멤버 함수 모두 지니고 있다.

	// insert()
	// insert(iter, 300);

	// erase()
	// erase(iter);



	// 리스트와 정렬
	// sort는 퀵정렬 >> 배열 기반으로 만들어짐

	// 리스트는 어떻게 정렬해?
	// 따로 정렬 멤버함수 sort()를 가지고 있다.
	// 퀵정렬, 노드 기반으로 설계됐다.
	// 첫번째 인자로 조건자를 받는다.


	// reverse()
	// 리스트를 뒤집는 멤버함수

#pragma endregion
		
}
