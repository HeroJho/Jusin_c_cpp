
#pragma region 반복자란?

// - 포인터와 비슷한 동작을하나, 포인터는 아님.
// - 컨테이너 원소를 접근하고 값 변경을 위한 목적의 "객체"!!
//			ㄴ인덱스 연산자가 있는 덱, 벡터, 맵을 제외하고는 반복자를 통해서 순회해야 한다.
// - 반복자는 각자의 컨테이너 마다 다르다(반복자의 구현 동작이 전부 다르다)

#pragma endregion


#pragma region 선언과 초기화

// vector<int>::iterator	iter = vecInt.begin();

#pragma endregion


#pragma region begin과 end의 위치

// b     i       e
// ㅁㅁㅁㅁㅁㅁㅁ

// - begin:		맨 첫번째 원소
// - end:		맨 마지막원소 다음(빈 공간)
// - 원소가 없을 때는 begin과 end가 같다!!

#pragma endregion


#pragma region iter순회 코드

//		vecInt.push_back(10);
//		vecInt.push_back(20);
//		vecInt.push_back(30);
//		
//		for (vector<int>::iterator iter = vecInt.begin();
//			iter != vecInt.end();
//			++iter)
//		{
//			(*iter) += 5;
//			cout << (*iter) << endl;
//		}*/

// - '!='는 연산자 오버로딩이 모든 컨테이너 다 되어있기 때문에 < 보다 사용된다

#pragma endregion


#pragma region 반복자의 종류 *중요!

	// 1. 출력(*만 오버로딩) 
	// 2. 입력(*, =) 
	// 3. 순방향(*, =, ++) 
	// 4. 양방향(*, =, ++, --) 
	// 5. 임의 접근 반복자 (*, =, ++, --, +=, -=, [])

	// 대부분의 컨테이너 반복자가 양방향 이상을 지원한다!
	
	// vector는 임의 접근 반복자 
	// list는 양방향 반복자

#pragma region 정리

	// 즉, 컨테이너에 따라서 반복자의 오버로딩된 멤버함수가 다르다!
	// 이건 해당 컨테이너의 특징을 잘 이해하고 있으면 암기할 필요가 없다!!

#pragma endregion

#pragma endregion