#include <iostream>
#include <vector>
#include <map>
#include <array>
using namespace std;


#pragma region mutable

// - �б� ���� �Լ� ������ �� ������ �����ϵ��� ���ִ� Ű����

class CObj
{
private:
	mutable int			m_iA;		// ���!
	int			m_iB;

public:
	void		Render() const // �б� ����(������ ���� �Ұ���)
	{
		m_iA = 30;
		//m_iB = 40;
	}

public:
	CObj() : m_iA(10), m_iB(20){	}
};

#pragma endregion


#pragma region try-catch

// - c++�� ����ó�� �����̴�.
// - if���� ��� �Ϲ����� ���α׷��� ���� �����ϴµ� �� ������ �д�.
// - ���� ó������ ������ �ʿ��ϴ�.


int main()
{
	int		iNum1, iNum2;

	cout << "���� �Է� : ";
	cin >> iNum1 >> iNum2;

	// if-else�� ����ó��
	if (0 == iNum2)
		cout << "0���� ���� �� �����ϴ�" << endl;
	else
	{
	cout << "�� : " << (iNum1 / iNum2) << endl;
	cout << "������ : " << (iNum1 % iNum2) << endl;
	}


	// try-catch�� ����ó��
	try
	{
		if (0 == iNum2)
			throw iNum2;	// �����͸� catch�� throw�Ѵ�!

		// ������ ���� ���ܰ� �߻��ϸ� ������ �ڵ� ����� �������� �ʰ� �ǳ� �ڴ�.
		cout << "�� : " << (iNum1 / iNum2) << endl;
		cout << "������ : " << (iNum1 % iNum2) << endl;
	}
	catch (int iNum2)
	{
		cout << "0���� ���� �� �����ϴ�" << endl;
	}

	return 0;
}


#pragma endregion


#pragma region auto

// - ����ڰ� ���� Ÿ���� �������� �ʾƵ� �Ǵ� ����
// - ���ϱ� ������, ������ �� ȥ���� �߱��� �� �ִ�.
// - ����� ���ÿ� �ʱ�ȭ�� ����� �Ѵ�.
// - �����Ϸ����� �Ǵܱ��� �ñ��. >> ���� �ʴ�!
// - ��ó�� ������ �ֱ� ������ ���� �����ϴ� ������ �ִ�

int main()
{
	auto	i = 10;
	cout << sizeof(i) << endl;

	auto	l = 10l;
	cout << sizeof(l) << endl;

	auto	f = 3.14f;
	cout << sizeof(f) << endl;

	auto	p = new int;
	cout << sizeof(p) << endl;

	// �ݺ��� ����� �����ϰ� �� ���� �ִ�.
	vector<int>			vecInt;
	vector<int>::iterator		iter = vecInt.begin();
	auto	iter = vecInt.begin();
}


#pragma endregion


#pragma region ���� ��� for��

// - �����ϰ�, �迭 �ε��� ������ �Ѿ�� �ൿ�� ������ �� �ִ�.

int main()
{
	int	iArray[5] = { 0, 1, 2, 3, 4 };

	for (int i : iArray)
		cout << i << endl; 


	vector<int>	vec;
	vec.push_back(10);
	vec.push_back(20);
	vec.push_back(30);
	vec.push_back(40);
	vec.push_back(50);

	// �����ڷ� ������ ������ ���� ����
	for (auto& iter : vec)
	{
		iter += 5;
		cout << iter << endl;
	}
}

#pragma endregion 


#pragma region ������ �ʱ�ȭ

struct tagInfo
{
	int X;
	int Y;
};

class  CObj
{
public:
	tagInfo		Get_Info()
	{
		return { 400, 100 };
	}

public:
	CObj(tagInfo _tInfo)
		: m_tInfo(_tInfo)
	{

	}
private:
	tagInfo		m_tInfo;
};

int main()
{
	int	iArray[5] = { 0, 1, 2, 3, 4 };
	// ������ �ʱ�ȭ
	int	iArray[5]{ 0, 1, 2, 3, 4 };		
	
	// struct ������ �ʱ�ȭ
	tagInfo	tInfo{ 10 , 20 };
	
	// class ������ �ʱ�ȭ
	//   ��private ����� ������ �ʱ�ȭ �� ���� �ݵ�� �Ű������� �ִ� �����ڰ� �־�� �����Ѵ�.
	CObj	Obj{ {100, 200} };

	// vector ������ �ʱ�ȭ
	vector<int>		vec{ 10, 20, 30, 40, 50 };
	cout << vec.size() << "\t" << vec.capacity() << endl;

	// map ������ �ʱ�ȭ
	map<int, int>	MyMap{ {1, 100},{ 2, 200 },{ 3, 300 } };
	for (auto mapiter : MyMap)
		cout << mapiter.first << "\t" << mapiter.second << endl;
}

#pragma endregion


#pragma region std::array

// - stl���� �������ִ� "���� �迭"�̴�.
// - #include<array>�� �ٿ���� �Ѵ�.
// - ������ ����ϴ� ���� �迭�� ��üȭ ��.
//		��������, �Ҹ���, ���� ������, ���� �����ڰ� �����Ǿ� �� �� ��ü���� �ٿ� �迭�� ���� �����ϴ�.
//		���ݺ���, empty, swap, front, back �Լ��� ����.
// - ���ʹ� ���� �迭�̾ ��� ����� ũ��. 
//      ��ũ�Ⱑ �̹� ������ ����� array�� ����ϴ� ���� ����.


int main()
{
	array<int, 5> arrEx; // { 1, 2, 3 };
	cout << sizeof(arrEx) << endl;

	int*	p = arrEx.data();	// �迭�� ù �ּҸ� ��ȯ�ϴ� �Լ�

	arrEx.fill(999);	// �迭�� ��� ���Ҹ� ���ڰ����� ä���ִ� �Լ�
	
	for (int i : arrEx)
		cout << i << endl;


	array<int, 5> arrTemp;

	arrTemp = arrEx;		// ���� ���� ������ ���� �� ���簡 �����ϴ�
}

#pragma endregion



#pragma region ���� vs ����

// ���� ���� >> ������ ������ Ÿ�ӿ� ������ ���� ��Ÿ�ӿ� �۾��� ���� ����.
// ������ �������� ��ƿ���� ������ ����, �����̳� �뷮�� �����ϸ� ������ ����.

#pragma endregion