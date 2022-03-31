#include "pch.h"

// �ʱ�* ������ �����ε��� Ŭ����
#pragma region ������ �����ε� �ڵ�

class CObj
{
private:
	int		m_iX;
	int		m_iY;

public:
	void		Render() { cout << m_iX << "\t" << m_iY << endl; }

	CObj		operator + (CObj& rObj)	// + �����ڸ� �����ε��� ��
	{
		CObj	Test(m_iX + rObj.m_iX, m_iY + rObj.m_iY);

		return Test;
	}
	CObj		operator + (int _iMove)	// + �����ڸ� �����ε��� ��
	{
		CObj	Test(m_iX + _iMove, m_iY + _iMove);

		return Test;
	}

	// ���� ������ �����ε�
	// ���� ���� ���� ���� �Ű澲��!
	CObj& operator =(CObj& rObj)
	{
		m_iX = rObj.m_iX;
		m_iY = rObj.m_iY;

		return *this;
	}


	// ���� ������ �����ε�
	CObj& operator ++(void) // ����
	{
		m_iX += 1;
		m_iY += 1;

		return *this;
	}
	// ����
	CObj operator ++(int) // int �� �����͸� �޴� ���� �ƴ϶� �����ε��� ���� ���� ����
	{
		CObj	Test(*this);

		m_iX += 1;
		m_iY += 1;

		return Test;
	}


public:
	CObj() {}
	CObj(int _iX, int _iY) : m_iX(_iX), m_iY(_iY) {}
	~CObj() {}
};

// ��ȯ ��Ģ �ذ� �� ���� �Լ� �������� ��. 
// ��ü Ÿ�Կ��� ��ü �����Ͱ� �ƴ� ���� ��ü Ÿ�԰� ��ü�� ���۷��� Ÿ���� �;��Ѵ�.
// operator+���� Ŭ���� ������ ���� �Ű� ������ ��� �ϳ��� �־�� �Ѵ�.
CObj	operator +(int _iMove, CObj& rObj)
{
	CObj		Test(rObj + _iMove);

	return Test;
}

#pragma endregion


int main()
{
#pragma region ������ �����ε��̶�?

	CObj Temp(100, 200);
	CObj Sour(300, 400);

	CObj Dest = Temp + Sour;  // ��� ���ض��?
	// �츮�� �����ϴ� ���·� �������� �Լ��� ����� ���ڴ� ��

	// ������ �����ε�: �����ڿ� ������ ��Ų �Լ� �����ε��� ���� 
	// >> ������ ��� �� ����(�� ���� �����ȴ�) >> Stl �����ڸ� ���� ����
	// ������ �����ε��� �޴� ���� ������ �� �ʿ�� ����!!

	// 1. ���� �������� ����� �ڹٲ� �� ����.
	// 2. ����� ���� �ڷ����� �� �����ϴ� �����̴�.
	// 3. Ŭ���� ����θ� ������ �� �ִ� ������ =, (), [], ->, ���� �������θ� ������ �����ϴ� �����ڵ� 
	//	��(��Ģ������ �׳� �Ǵ� ��)

#pragma endregion


#pragma region ��ȯ ��Ģ

	// ȣ�� ��ü�� ����, �������� ���� >> ��ȯ ��Ģ�� �������� �ʴ´�!
	// Temp.+(Sour);
	// ��ȯ��Ģ �ذ� �� ���� �Լ��� ������ �Ѵ�. 
	// ��ü Ÿ�Կ��� ��ü �����Ͱ� �ƴ� ���� ��ü Ÿ�԰� ��ü�� ���۷��� Ÿ���� �;��Ѵ�.
	// operator+���� Ŭ���� ������ ���� �Ű� ������ ��� �ϳ��� �־�� �Ѵ�.

#pragma endregion


#pragma region ���� ������ �����ε�

	// ����Ʈ ���� ������ ����.
	// ���� ���� ���� >> ���� ���� �������� �����
	
#pragma endregion


#pragma region ���� ������ �����ε�

	// ++, --

	// ����
	// �ڽ��� ��ȯ�Ѵ� (���޾Ƽ�)
	++(++Temp);

	// ������ ��� �����?
	// �Լ� ���ڿ� int�� �ٿ��� �����ε��� ���� ���� ������ ����Ѵ�.(��ÿ�)
	// ������ ��ü�� ���� ��ȯ�Ѵ� (���޾� x)

#pragma endregion


	
#pragma region cout << ������ �����ε�
	
	// cout�� Ŭ������

	/*
namespace MyStd
{
	class Ostream
	{
	public:
		Ostream&	operator <<(int iDest)
		{
			printf("%d", iDest);

			return *this;
		}

		Ostream&	operator <<(char* pDest)
		{
			printf("%s", pDest);

			return *this;
		}
	};

	Ostream		COUT;
	char*		ENDL = "\n";

}

using namespace MyStd;

void main(void)
{
	COUT << 100 << ENDL;
}
*/

#pragma endregion



#pragma region () ������ �����ε��� ����

#pragma region �ڵ�

#pragma region �⺻ ����
/*
class CObj
{
public:
	int	operator() (int iTemp, int iSour)
	{
		return iTemp + iSour;
	}
};

void main(void)
{
	CObj	Obj;
	cout << Obj(10, 20) << endl;
}*/
#pragma endregion


#pragma region ���� �ٲٱ�
/*
class CSortRule
{
public:
	virtual bool	operator()(int iTemp, int iSour) = 0;
};

// ��������
class CAsendingSort : public CSortRule
{
public:
	virtual bool operator()(int iTemp, int iSour)
	{
		if (iTemp > iSour)
			return true;

		return false;
	}

};

// ��������
class CDesendingSort : public CSortRule
{
public:
	virtual bool operator()(int iTemp, int iSour)
	{
		if (iTemp < iSour)
			return true;

		return false;
	}
};

void	Bubble_Sort(int* pArray, int iSize, CSortRule& Functor)
{
	for (int i = 0; i < iSize; ++i)
	{
		for (int j = 0; j < iSize - 1; ++j)
		{
			if (Functor(pArray[j], pArray[j+1]))
			{
				int	iTemp = pArray[j];
				pArray[j] = pArray[j + 1];
				pArray[j + 1] = iTemp;
			}
		}
	}
}

void main(void)
{
	int		iArray[5] = { 1, 3, 4, 2, 5 };

	CAsendingSort		Asen;
	CDesendingSort		Desen;

	Bubble_Sort(iArray, 5, Desen);

	for (int i = 0; i < 5; ++i)
	{
		cout << iArray[i] << endl;
	}

}*/
#pragma endregion

#pragma endregion
	
	// �Լ� ��ü(����) : ()������ �����ε��� ���� ��ü�� �Լ�ó�� ����ϴ� ����
	// STL�� �Լ� ��ü�� ����� �Լ� ��� ����Ѵ� >> ������

	// �� �����?
	// ������(�������̵�)�� �̿��� �Լ��� �����ϰ� ����ϱ� ���ؼ�
	// �������� �������� ���� >> ������ ����

	// ���� ȣ�� ���忡�� ���� � ��ü�Ŀ� ���� ���� �ٸ� ���¸� ǥ���� �� �ִ�.
	// �Լ� ��ü�� Ŭ���� ����ο� ��ü���� ���ǵǾ� �ֵ��� �ش� ��� �Լ��� �ڵ� inlineȭ �Ǿ� �Ϲ� �Լ��� ���� �ӵ��� ������
	// inlineȭ �޴µ� virtual�� ���� �ӵ��� �پ��� ���! >> virtual�� �� �� �Ѵ�.(���)

#pragma endregion


#pragma region �ӽ� �޸�

	// �ӽ� ��ü
CObj("�ӽ� ��ü"); // �ӽ� ��ü�� �ش� �ڵ������ ����� �Ҹ�ȴ�.
// �ٷ� �Ҹ�

// �Լ� ���͵��� �ӽ� ��ü�� ����� �޸� ȿ���� ���δ�

#pragma endregion

}

// stringŬ����
// ==(strcmp), +(strcat), =(strcpy) �����ε� �غ���