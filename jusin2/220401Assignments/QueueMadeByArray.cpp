#include "pch.h"
#include "QueueMadeByArray.h"

QueueMadeByArray::QueueMadeByArray()
{
}
QueueMadeByArray::~QueueMadeByArray()
{
}

void QueueMadeByArray::Push(int _iValue)
{
	m_arr.Push(_iValue);
}

int QueueMadeByArray::Pop()
{
	if (1 > m_arr.GetSize()) {
		cout << "배열이 비어있습니다." << endl;
		exit(1);
	}

	int temp = m_arr[0];
	
	// Queue의 경우 배열로 구현하면 레코드의 이동이 너무 많음!
	// >> 원형 큐로 구현
	// >> 연결 리스트로 구현
	for (int i = 1; i < m_arr.GetSize(); ++i)
		m_arr[i - 1] = m_arr[i];

	m_arr.Pop();

	return temp;
}
