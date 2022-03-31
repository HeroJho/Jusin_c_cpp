// 여전히 부모 클래스에 함수들이 몰리는 것이 해결되지 않는다.
	// 해결을 위해 캐스팅이 필요하다.
	// 캐스팅 = 형 변환!
	// 해결: 포인터를 '부모 > 자식' (업 케스팅)해서 해당 자식의 멤버 함수를 호출하면 된다.


#pragma region 캐스팅

	// CObj* pObj = new CPlayer;
	// ((CPlayer*)pObj)->Print(); // c의 캐스팅(형 변환)

	// 1. 캐스팅은 내부적인 동작 비용이 많이 발생하여 프로그램 전반의 속도를 저하시킨다.
	//		무분별하게 쓰는 것을 최대한 자제해야한다! 
	//		>> 쓰지말라는 것은 아니다! 캐스팅은 해야하니깐!
	// 2. c캐스팅이 무조건 형 변환을 허용하기 때문에 위험성이 다분이 높다!
	//		ㄴ기능, 성능 자체는 우수하다.



	// 2의 문제를 극복하고자 c++의 캐스팅 연산자가 등장했다.


	// oop, RTTI, 콜백 >> 면접에서 자주 나오는
	// ex) RTTI 문법을 사용해본 경험이 있나요?

	// c++ 캐스팅 연산자
	// 지금 배울 4가지 캐스팅 RTTI의 문법이다
	//    ㄴ런타임에 포인터가 실제 어떤 객체를 가리키는지 알고 싶을때 typeid
	// <변환하고 싶은 자료형>(변환할 데이터)
	// 1. static_cast<>();
	// 2. dynamic_cast<>();
	// 3. const_cast<>();
	// 4. reinterpret_cast<>();

#pragma endregion


	// 면접 질문: static과 dynamic의 차이점을 말해보세요.
#pragma region static_cast

	// 특징:
	//	1) 논리적인 형변환을 수행
	//	2) 우리가 늘 써오던 c스타일 캐스팅과 흡사
	//	3) 형변환 시점이 "컴파일 시점"이기 때문에 static이라는 이름을 붙어졌다.
int iNumber = static_cast<int>(3.14f);


// 논리적이지 않은 캐스팅 상태 1
{
	// CPlayer*	pPlayer = new CPlayer;

	// Monster*	pObj = (Monster*)pPlayer; // 허용
	//		ㄴc 형변환은 상속의 유무를 따지지 않는다. >> 무조건 변환

	// Monster*	pObj = static_cast<Monster*>(pPlayer); // 에러 
	//		ㄴ상속이 아닌 상태에서 강제적인 형 변환은 불가능하다. 
	//		ㄴ상속 관계 유무를 논리적으로 따지는 캐스팅
}
// 논리적이지 않은 캐스팅 상태 2
{
	//CObj*		pObj = new CObj;

	//CPlayer*	pPlayer = pObj;		
	//		ㄴ객체 포인터는 부모, 자식을 판단할 수 없다. 
	//		ㄴ지금처럼 서로 알 수 없는 상황에서 단순 대입 시 컴파일 에러가 발생

	//CPlayer*	pPlayer = static_cast<CPlayer*>(pObj);
	//		ㄴ다운 캐스팅
}


// static_cast 장단점
{
	//단점
	// 1) 자식 객체 포인터에 부모 객체의 정보를 넣도록 허용하는 행위가 과연 코드적으로 논리적인가?
	// 2) 컴파일 시점인 정적 캐스팅에 해당하다 보니 런타임 시에 타입 체크를 하지 않아 정상적인 형 변환의 인지가 확인 불가.
	// 장점
	// 1) 속도가 빠름
	// 2) 일반적으로 손쉽게 사용(원시 데이터 캐스팅에도 사용 가능)
}

// 생각 정리
// static_cast는 c캐스팅과 다르게 상속의 여부를 판단해 준다.
//	ㄴ컴파일 시점에 일어나기 때문에 빠르다.
// 하지만, 다운 캐스팅(부모 > 자식)역시 허용하기 때문에 논리적이지 않은 캐스팅도 허용한다.
//  ㄴ이것은 온전히 프로그래머의 실수이다. 컴파일러가 잡아주지 않는다.

#pragma endregion


#pragma region dynamic_cast

	// 특징
	// 1) 반드시 "가상 함수를 하나 이상 포함"한 상속관계일 때 "다운 캐스팅(부모 > 자식)"을 하기 위한 캐스팅
	// 2) 안전하지 않은 캐스팅을 허용할 경우 nullptr을 반환한다.
	//   ㄴ부모 객체를 자식 포인터로 관리 되도록 캐스팅되는 상황
	// 3) 런타임에 안전한지 불안전한지 체크해 주기 때문에 dynamic
	// 4) 일반자료형, 일반포인터 사용 불가능


	// 안전하지 않은 다운 캐스팅
{
	/*	CObj*		pObj = new CObj;
		CPlayer*	pPlayer = dynamic_cast<CPlayer*>(pObj);

		if (nullptr == pPlayer)
		{
		cout << "안전하지 않은 캐스팅" << endl;
		} */
}
// 안전한 다운 캐스팅
{
	//CObj*		pObj = new CPlayer;
	//CPlayer*	pPlayer = dynamic_cast<CPlayer*>(pObj);
	//pPlayer->Render();
}

#pragma endregion


// 생각 정리
// c형변환		: 무조건 변환
// static_cast	: 상속 유무 확인(컴파일)
// dynamic_cast : 상속 유무(추상 클래스) + 안전한 캐스팅인지 확인(런타임)


#pragma region 업케스팅

	// 업 캐스팅 (자식 >> 부모)
	//CPlayer*	pPlayer = new CPlayer;
	//CObj*		pObj = pPlayer;		// 묵시적 업 캐스팅

	// 명시적 업 캐스팅
	//CObj* pObj = dynamic_cast<CObj*>(pPlayer); 
	//CObj* pObj = static_cast<CObj*>(pPlayer);

#pragma endregion


#pragma region const_cast & reinterpret_cast

	// const_cast
	//		일시적으로 const를 벗겨주는 케스팅
	//		포인터가 참조하고 있는 원본 값 변경이 불가능할 때 다른 포인터를 통한 원본 값 변경을 위해 일시적으로 const 성격을 벗겨낼 수 있다.
	//		단, 포인터 또는 레퍼런스 형만 사용할 수 있따.

	// reinterpret_cast
	//		const 포인터를 제외한 모든 포인터의 형변환을 허용, 심지어 비 논리적인 형 변환마저 허용
	//		예측할 수 없는 결과를 초래하기 때문에 사용을 자제하는 편이다.
	//		상속관계가 아닌 애들까지도...

#pragma endregion





	// 결론
	// 안전한지 안한지 직접 판단해서 (논리적으로) static을 쓸건지, dynamic 쓸건지 결정하자.
	// 정말 확신이 있는 안전한 캐스팅이라면 static을 쓰자!
	// static을 대부분 쓰고, 필요에 따라 안전하게 런타임 체크를 하고 싶다면 dynamic을 사용한다.
	// 그 외 const reinterpret_case 는 거의거의 사용 안 한다.

	// 안전한 캐스팅에 대해 설명 해 봐라. 
	//   ㄴ캐스팅 자체는 그냥 불안전하다. RTTL는 상대적으로 안전하다는 것이다.
