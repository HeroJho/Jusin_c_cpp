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
		cout << "�迭�� ����ֽ��ϴ�." << endl;
		exit(1);
	}

	int temp = m_arr[0];
	
	// Queue�� ��� �迭�� �����ϸ� ���ڵ��� �̵��� �ʹ� ����!
	// >> ���� ť�� ����
	// >> ���� ����Ʈ�� ����
	for (int i = 1; i < m_arr.GetSize(); ++i)
		m_arr[i - 1] = m_arr[i];

	m_arr.Pop();

	return temp;
}
