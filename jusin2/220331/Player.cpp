#include "stdafx.h"
#include "Player.h"


// 함수는 파일 단위로 사용할 수있따.
// 그래서 범위 지정자로 명시해줘야 한다.
// Player라는 자료형 안에 있는 Render함수
void Player::Render()
{
	cout << m_iHp << endl;
}
