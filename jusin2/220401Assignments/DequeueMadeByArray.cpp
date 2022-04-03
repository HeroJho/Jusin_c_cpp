#include "pch.h"
#include "DequeueMadeByArray.h"

DequeueMadeByArray::DequeueMadeByArray()
{
}

DequeueMadeByArray::~DequeueMadeByArray()
{
}


int DequeueMadeByArray::Pop_Front()
{
	// queue.pop()
	return Pop();
}

int DequeueMadeByArray::Pop_Back()
{
	return m_arr.Pop();
}

void DequeueMadeByArray::Push_Front(int _iValue)
{
	if (1 > GetSize())
	{
		Push_Back(_iValue);
		return;
	}

	// 맨 끝에 있는 애를 PushBack
	// 1 2 3 4 5 6 6
	int temp = m_arr[GetSize() - 1];
	Push_Back(temp);
	
	// 민다
	// 1 1 2 3 4 5 6
	for (int i = m_arr.GetSize()-2; 0 <= i ; --i)
		m_arr[i + 1] = m_arr[i];

	// 넣는다
	// o 1 2 3 4 5 6
	m_arr[0] = _iValue;
}

void DequeueMadeByArray::Push_Back(int _iValue)
{
	Push(_iValue);
}
