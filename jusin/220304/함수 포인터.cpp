#include <iostream>

using namespace std;

void Rand()
{
	cout << 1 << endl;
}
int Get_A(int iA)
{
	return iA;
}
int Add(int iA, int iB)
{
	return iA + iB;
}
int Minus(int iA, int iB)
{
	return iA - iB;
}

void main()
{
#pragma region �Լ� ������

	// �Լ� ������ : �Լ��� �̸��� �����ϱ� ���� ������
	// �Լ��� �̸� ���� �Լ��� ��ϵ� �޸� ����(code)�� �ּ� ���� �ش��Ѵ�.
	// �Լ� �̸�()   : () �Լ�ȣ�� ������
	cout << Rand << endl;  // �Լ� �̸� >> �̸��� ������ �ּҰ��� ������ >> ������ �ڵ� �����̶� ������ �Ұ���

	// ���� �Լ� �����͸� ������ �����ϴ� ���·� ���� �Լ��� �ٲٸ鼭 ����ϰڴٴ� ��
	// c������ ������ ���� �����̿����� c++���� Ŭ������ �����鼭 Ż���Ǿ�� �����̴�.
	// ������ ������ ������ �ʿ�� �ִ�. >> c ����ü�� ������ ���� > �Լ�������� �Լ� ������ ����� > c++�� Ŭ������ �׳� ���� �� ����

	// ����
	// Ÿ��(*������)(�Ű�����) : �߰� ������ �־ �������
	void(*ptrVoid)(void) = Rand;
	ptrVoid();

	int(*ptrGet)(int) = Get_A;
	cout << ptrGet(10) << endl;

	int(*ptrAdd)(int, int) = Add;
	cout << Add << endl;

#pragma endregion


	// �Լ� ������ ��뿹
	{
		int(*ptrAdd)(int, int) = Add;
		cout << Add << endl;
	}
}

