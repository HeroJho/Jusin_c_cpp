#include <iostream>

// 맵 헤더
#include <map>
using namespace std;

int main()
{
	// deqeu
	// 블로그 자료로 정리하기
	// 학원에서는 벡터를 주로 사용함


#pragma region map이란?

	// 1. 연관 컨테이너 (비 선형적)
	// 2. 자가 균형 이진 탐색 트리(레드 블랙 트리)기반
	// 3. 중위 순회 기반
	

	// 탐색의 용이한 컨테이너이기 때문에 잘 쓰인다!
	//		ㄴex) 리소스 탐색
	// 탐색을 위한거면 해쉬맵이 좋지 않나?
	//		ㄴ일단 이전 c++에서는 해쉬맵(unodered map)이 제공되지 않았다!
	//      ㄴ또한 해쉬맵이 이진 탐색 트리보다 불리할 경우가 있다!

	// key값은 바뀌면 안되기 때문에 const상태로 받아야 한다

#pragma endregion
	
#pragma region 특징

	// 1. key와 value, 한 쌍의 데이터를 원소로 삼는다.
	// 2. key값 기준으로 자동 정렬을 수행한다.
	//		ㄴ빈번한 삽입 삭제가 발생할 경우 속도가 매우 느리다.
	//		ㄴkey값에 따라 정렬이 되어있기 때문에 반복자를 통한 탐색이 가능하다.
	// 3. map은 노드 기반 컨테이너 중, 유일하게 []연산자가 오버로딩 되어있어 '키 값'으로 임의접근이 가능하다
	//		ㄴmap["Player"] = 100;
	//		ㄴ임의접근인 척 하는거지 += -=를 사용은 불가능하다!
	// 4. map은 양방향 반복자를 갖고 있다.
	// 5. map은 중복 key 값을 허용하지 않는다
	// 6. 이항 템플릿이다. (두 개 이상)
	//		ㄴmap<key값의 자료형, value값의 자료형, 조건자>

#pragma endregion

#pragma region 선언

	// - map<key값의 자료형, value값의 자료형, 조건자>
	// - 보통은 조건자는 건들지 않는다

	map<int, int>		MapInt;
	map<char*, CObj*>
	map<string, list<CObj*>>

#pragma endregion


#pragma region pair객체

	// - map의 원소 삽입을 위하여 pair객체가 필요하다.
	// - 한 쌍을 이루는 원소를 템플릿화 하여 저장할 수 있는 형식으로 만드는 것.
	// - 원소에 대입하여 값 변경 가능, 선언만 하고 초기화하지 않는다면 자동 0 초기화
	
	pair<int, int>		MyPair;
	
	MyPair.first = 2;
	MyPair.second = 200;

#pragma endregion
	
#pragma region 다양한 원소 삽입 방법


#pragma region insert와 pair 객체를 만들어서 원소를 삽입하는 방법 
	
	// - insert를 하기 위해서 pair객체를 넣어줘야 한다
	// - 키값에 해당하는 노드가 존재하지 않는다면 해당 키와 value로 구성된 노드를 생성하여 삽입하는 함수
	//      ㄴ즉, 노드가 무조건 있어야 한다. 그래서 pair가 0으로 자동 초기화되는 이유!
	
	pair<int, int>		MyPair(2, 200);
	MapInt.insert(MyPair);

	// 임시 객체
	MapInt.insert(pair<int, int>(1, 100));

#pragma endregion
 
#pragma region [] 연산자를 통한 원소 삽입

	// - 해당 인덱스 값의 노드가 없는 경우 노드를 생성하여 value로 값을 대입
	// - 해당 인덱스 값의 노드가 있는 경우 value 값만 대입이 가능

	MapInt[2] = 200;

#pragma endregion

#pragma region insert와 []대입의 차이

	// - insert는 무조건 노드를 생성하라는 문법. (키가 겹쳐도-> 중복 키 허용 안 하니 삽입x)
	// - [] 대입은 노드가 없으면 생성하고, 있으면 값만 변경하라는 문법

#pragma endregion


#pragma region make_pair함수를 이용한 원소 삽입 방법

	// - pair 객체를 직접 생성하는 것보다 작동속도가 떨어진다
	
	MapInt.insert(make_pair(3, 300));

#pragma endregion
	
#pragma region value_type을 이용한 원소를 삽입하는 방법 (권장)

	// - 데이터 삽입의 정규 문법이다.
	// - 키는 const이기 때문에 대입 불가능
	// - namespace에 정의되어 있어서 ::연산을 사용해야 함 
	// - 선언만 하고 초기화하지 않을 경우 자동 0으로 초기화된다.

	map<int, int>::value_type	MyMap(4, 400);	
	MapInt.insert(MyMap);

	MyMap.first = 5;	// 불가능
	MyMap.second = 500;

#pragma endregion
#pragma region value_type 임시 객체를 이용하여 원소를 삽입하는 경우

	MapInt.insert(map<int, int>::value_type(5, 500));

#pragma endregion

#pragma region emplace 함수를 이용한 원소 삽입 경우 (권장)

	// - c++11이후에 나온 함수이다.
	
	MapInt.emplace(6, 600);

#pragma endregion

#pragma region 유니폼 초기화를 이용한 원소 삽입 경우 (가장 권장)

	// - c++11이후 발생한 방법이다.
	
	MapInt.insert({7, 700});

#pragma endregion


#pragma endregion


#pragma region map 컨테이너의 각종 멤버 함수

	// - size(), clear(), empty(), begin(), end() 가능!
	// - front back류는 없다!(시퀀스 컨테이너 전용)

#pragma region insert()의 중간 삽입

	// - map은 자동정렬이 일어나기 때문에 중간 삽입을 하더라도 큰 의미가 없다.
	// - 중간 삽입해도 반복자의 무효화가 일어나지 않는다.												

	map<int, int>::iterator		iter = MapInt.begin();
	// iter += 3;		// map 컨테이너는 임의 접근이 불가능한 양방향 반복자를 갖고 있다.
	++iter;
	++iter;

	MapInt.insert(iter, { 6, 600 });		

#pragma endregion

#pragma region erase()의 중간 삭제

	// erase를 통한 삭제 시에는 반복자의 무효화가 일어나기 때문에 반드시 다음 반복자를 반환해주거나 begin 위치로 초기화 해야한다.
	
	iter = MapInt.erase(iter);				
	cout << iter->first << "\t" << iter->second << endl;

#pragma endregion

#pragma region find()의 탐색

	//	Map.find(키값);

#pragma endregion

#pragma region char*와 같은 포인터형 키값의 탐색에서는 문제점

	// 멀티 쓰레드 기반의 프로그래밍, dll기반의 다중 프로젝트라고 했을 때,
	// 각각의 프로젝트의 가상주소가 다르기 때문에 포인터형 키값을 사용할 시
	// 키값이 달라지는 문제가 생긴다.
	
	// 주소(포인터)말고 특정 조건(문자열 그 자체)을 통해 탐색하고 싶을 때 find_if()을 사용한다.

#pragma endregion

#pragma region find_if()

	// - 특정 조건자를 사용해서 찾는다. 
	// - 키 값 비교를 위해 인자를 넘겨줘야하니 펑터를 사용한다.

	class CTag_Finder
	{
	private:
		char* m_pTag;

	public:
		CTag_Finder(char* pTag)
			: m_pTag(pTag) {	}

	public:
		template<typename T>
		bool	operator()(T& Pair)
		{
			if (!strcmp(Pair.first, m_pTag))
				return true;

			return false;
		}
	};

	map<char*, int>		MapChar;

	MapChar.insert({ "AAA", 100 });
	MapChar.insert({ "BBB", 200 });
	MapChar.insert({ "CCC", 300 });

	map<char*, int>::iterator		iter = MapChar.begin();

	for (iter = MapChar.begin(); iter != MapChar.end(); ++iter)
		cout << iter->first << "\t" << iter->second << endl;

	// iter = MapChar.find("AAA");	// 0x16 , 0x27

	iter = find_if(MapChar.begin(), MapChar.end(), CTag_Finder("AAA"));

#pragma endregion


#pragma endregion


#pragma region 문자열이 키 값일 때 정렬은 어떻게 되는가 

	// 1. key값이 char형인 경우 아스키코드 값, 즉 알파벳 순으로 정렬이 일어난다.
	// 2. key값이 char*형인 경우 16진수 주소, 정수값 기준으로 정렬이 일어난다.
	// 3. key값 정렬을 문자열 기준으로 하고자 한다면 char*이 이니라 string을 사용해야 한다.
	//		ㄴstring 컨테이너는 내부에 문자열 대조비교가 오버로딩 되어있다.
	// 4. char* 형(주소)을 굳이 정렬하고 싶다면 조건자를 직접 만들어서 비교 함수를 만들어야 한다.

#pragma endregion
	

	return 0;
}
