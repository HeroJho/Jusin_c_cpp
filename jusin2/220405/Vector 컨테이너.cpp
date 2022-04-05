#include <vector>
using namespace std; // 멤버함수 정의등 있으니 꼭 std uing 해주기

// 보편적인 멤버함수만 공부한다. (나머지는 필요할 때마다 레퍼런스 참고)!!


int main()
{
#pragma region 선언과 네이밍

	vector<int>		vecInt;
	vector<float>	vecFloat;

#pragma endregion


#pragma region push_back, pop_back

	// 앞과 뒤가 있다는 것은 선형적인 구조에서만 가진다(비선형은 앞 뒤 개념이 없다)
	// 앞뒤가 열린 덱, 리스트는 앞 관련 함수도 추가로 가지고 있다

	//push_front() : deque와 list 사용 가능
	//pop_front() : deque와 list 사용 가능
	//push_back() : 모든 시퀀스 컨테이너 사용 가능
	//pop_back() : 모든 시퀀스 컨테이너 사용 가능

#pragma endregion


#pragma region 임의 접근 연산자

	// 벡터는 배열 기반이기 때문에 []연산자(오버로딩 된)를 사용할 수 있다!
	// 임의접근 가능



	// vecInt[3] = 777;		// 인덱스 접근을 통한 원소의 값 변경이 가능

	// for (size_t i = 0; i < vecInt.size(); ++i)
	//	 cout << vecInt[i] << endl

#pragma endregion


#pragma region size()

	// size() 컨테이너 원소의 개수를 반환 (모든 컨테이너가 가진다)

	// size는 sizt_t로 반환한다!!
	//  ㄴsize_t : unsigned int  

#pragma endregion

#pragma region clear()

	// -컨테이너 내의 모든 원소를 제거한다.
	// -모든 컨테이너가 갖는다.

#pragma endregion

#pragma region empty()
 
	// -컨테이너 내의 원소의 유무를 판단하는 함수
	// -모든 컨테이너가 갖는다.

#pragma endregion

#pragma region swap()

	// 같은 타입의 컨테이너끼리 원소와 '메모리 공간'을 교환한다

#pragma endregion

#pragma region capacity()

	// - 벡터만 가지는 유일한 함수이다!

#pragma region 벡터의 메모리 할당 정책
	
	//	1) 벡터는 동적 배열
	//	2) 꽉차면 재할당한다
	//	3) 추가할 때마다 할당하면 비효율적
	//	4) 재할당을 최소화할 정책을 세움

	// 정책은 사용하는 컴파일러마다 다르다!
	// 비줠스튜의 카파시티 정책: n + n/2



	/*for (int i = 0; i < 20; ++i)
	{
		cout << "사이즈 : " << vecInt.size() << "\t카파시티 : " << vecInt.capacity() << endl;
		vecInt.push_back(10);
	}*/

#pragma endregion


	// clear()하면 size는 0이 되지만, 카파시티는 그대로다(작은걸로 굳이 재할당하지는 않는다)
	//  ㄴpop도 마찬가지.

#pragma region capacity 지우기

	// 과거에는 제공되는 함수가 없었지만, 지금은 생겼다
	//		ㄴ그래서 제공되는 함수를 사용해도 되지만, 현재도 옛 방법을 많이사용.
	//		ㄴ성능적으로도 옛 방법이 좋음.

	// 옛 방법 지우기
	//		임시 객체 생성을 통한 교환
	//		vector<int>().swap(vecInt);
	
	
	// 하지만 잘 하지 않는다!! >> 귀찮아서...
	//    ㄴ카파시티 안 지운다고해서 ... 프로그램에 지장이 전혀~없다 . 메모리 공간은 넘친다!!

#pragma endregion

#pragma endregion

#pragma region front(), back()

/*vector<int>	vecInt;

	vecInt.push_back(10);
	vecInt.push_back(20);
	vecInt.push_back(30);
	vecInt.push_back(40);
	vecInt.push_back(50);

	vecInt.front() = 100;		// 맨 앞의 원소의 메모리 공간에 접근가능한 함수
	vecInt.back() = 5000;		// 맨 뒤의 원소의 메모리 공간에 접근가능한 함수

	//cout << vecInt.front() << endl;
	//cout << vecInt.back() << endl;

	for (size_t i = 0; i < vecInt.size(); ++i)
	{
		cout << vecInt[i] << endl;
	}*/

#pragma endregion

	return 0;
}


