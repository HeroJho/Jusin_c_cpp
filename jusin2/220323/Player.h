#pragma once

//#include "Monster.h"

class CMonster;		// ���� ����(�ڷ����� ���� �Ǵܸ� �һ� Ŭ���� ���� ������ �Լ��� ���� ������ ���� �� ���� ����)

// 1. ���� ���� ����, ��ü Ÿ���� ��� ������ ������ �Ұ��Ͽ� �ݵ�� ������ Ÿ������ �����ؾ� �Ѵ�.
// 2. cpp���Ͽ� ��������� �޵�� �����Ͽ� �ڷ��� �Ǵ� �Լ��� ȣ�� ������ �ο��� �� �ְ� �ؾ� �Ѵ�.

class CPlayer
{
private:
	int			m_iA;
	CMonster* m_pMonster;

public:
	void		Render() { cout << m_iA << endl; }
	void		Draw(void);

public:
	CPlayer();
	~CPlayer();
};

