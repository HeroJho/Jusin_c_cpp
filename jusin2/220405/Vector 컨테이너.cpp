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

	// push_front() : deque와 list 사용 가능
	// pop_front()	: deque와 list 사용 가능
	// push_back()	: 모든 시퀀스 컨테이너 사용 가능
	// pop_back()	: 모든 시퀀스 컨테이너 사용 가능

#pragma endregion


#pragma region 임의 접근 연산자

	// 벡터는 배열 기반이기 때문에 []연산자(오버로딩 된)를 사용할 수 있다!
	// 임의접근 가능

	// vecInt[3] = 777;		// 인덱스 접근을 통한 원소의 값 변경이 가능

	// for (size_t i = 0; i < vecInt.size(); ++i)
	//	 cout << vecInt[i] << endl

#pragma endregion


#pragma region 자주 쓰이는 멤버 함수

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



#pragma region capacity() *중요

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

#pragma region insert()

	// 임의의 위치에 원소를 삽입하는 함수
	// vecInt.insert(iter, 60000);

#pragma endregion



#pragma region erase() *사용법 특이! 중요!

	// 임의의 위치에 원소를 삭제하는 함수
	// iter = vecInt.erase(iter);


	// 삭제 후 그냥 iter를 접근하려면 터진다
	vecInt.erase(iter);	
	cout << (*iter) << endl;

	// 왜?
	// iter: 원소를 가리키기위한 객체 (메모리를 가리키는 용도가 아니다!)
	// 원소가 삭제됐다 >> 가리키는 원소가 없는데?
	// 반환값이 원소를 새로 가리킨 이터
	// 이터의 역할: 삭제를 한 뒤에 다음 원소를 가리키는 이터를 반환!! 반환값으로 받아줘야 한다!

	// 리스트를 생각해보자!
	
#pragma endregion



#pragma endregion


#pragma region 메모리 확보를 위한 vector의 함수들


#pragma region 생성자 사용

	vector<int>		vecInt(10);
	// 생성 시점에 원소 값이 0으로 초기화된 상태로 사이즈와 카파시티를 미리 10개 만들어주는 문법
	//     ㄴsize == 카파시티
	// 이러니 push_back하면 바로 재할당이 일어남

#pragma endregion

#pragma region resize()

	vecInt.resize(2);		
	// 원소의 개수를 다시 조정하는 함수.
	//    ㄴ단, 이미 확보된 메모리 공간(카파시티)은 줄어들지 않는다.

	vecInt.resize(50);
	// 증가를 시키면 그만큼 재할당(카파시티 증가)한다.

#pragma endregion

#pragma region reserve()

	vecInt.reserve(10);	
	// 원소 개수 변동 없이 오로지 메모리 공간을 미리 확보하는 함수
	// size는 0이고 캐퍼시티만 늘린다

#pragma endregion


#pragma region 정리

	// 결국 생성자를 통해 공간 확보를 하고 resize함수를 쓰는 것 보다
	// reserve를 쓰는게 편하다.
	// 하지만 이마져도 메모리 공간을 알아서 해주니 메모리 확보 관련 함수들은 잘 사용을 안 하게된다.

#pragma endregion


#pragma endregion





	return 0;
}


