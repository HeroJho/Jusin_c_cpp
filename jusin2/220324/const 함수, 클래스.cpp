#include "pch.h"

#pragma region Ŭ���� �ȿ��� �����ϴ� �Լ��� ���ȭ

// const >> �б� �������� ����ϰڴٴ� ���̴�

class COBj
{
private:
	const int m_iA = 10;
public:
	// �б����� �Լ�
	void Render() const
	{
		// m_iA = 20;     // ���� ����� ������ �� ����
		cout << m_iA;

		Draw();    // ������ �ܰ迡���� ���Ǹ� �� �� ����. >> �������� ���� ���ɼ��� �����ִٴ� ���̴�.
		DrawC();	// �ʵ� �б� �����̱���? ���� ����Ѵ�
	}

	void Draw()
	{
		cout << "Hi" << endl;
	}

	void DrawC() const
	{
		cout << "Hi" << endl;
	}

	// const�� ���� ���� �����ε��� �����̴�
	// const�� ���� ��ü�� ȣ���ϸ� const�Լ��� ȣ���Ѵ�
	void Draw() const
	{
		cout << "constDraw" << endl;
	}

public:
	// const + ������  : �޸� ���� ���� >> ���� ����

	const int& Get_A()  // �׳� int�� ��ȯ�ϸ� �ӽø޸� �߻� >> ������ ��� >> const�� ��ȯ�ϴ� �����ڵ� const���
	{
		return m_iA;
	}

	const int& Get_A() const // �ظ��� get�Լ��� �̷������� ���踦�ص� �����ϴ�
	{
		return m_iA;
	}

	void Set_A(const int& _iA)
	{
		m_iA = _iA;     // �Ű������� ����� �޾Ƽ� �� ������ ���� �ʴ� ���
		_iA = 10;		// �޸� ���簡 �߻��� ���� ����, const�� �ٿ��� �� ������ ����
	}
};

// �Ϲ����� ����Լ��� ���� const�� �ٿ��� ���ڰ� �б� �������� �ع����� �ȵȴ�.
// ���� �� �ִ� ������ ��������.   >> �� �ƴϰ�... �׳� ��������

// ����ο� ���Ǻη� �����ٸ�
// ��ü���� �Ȱ��� const�� �ٿ���� �Ѵ�

#pragma endregion

void main()
{
	COBj co;
	cout << co.Get_A();
}