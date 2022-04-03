#include "pch.h"
#include "DynamicArray.h"

DynamicArray::DynamicArray()
	: m_arrInt(nullptr)
	, m_iCapacity(3)
	, m_iCount(0)
{
	m_arrInt = new int[m_iCapacity];
}
DynamicArray::~DynamicArray()
{
	SAVE_DELETE(m_arrInt);
}

void DynamicArray::Push(int _iValue)
{
	if (m_iCount >= m_iCapacity) {

		m_iCapacity *= 2;
		int* p = new int[m_iCapacity];
		
		for (int i = 0; i < m_iCount; ++i)
			p[i] = m_arrInt[i];

		SAVE_DELETE(m_arrInt);

		m_arrInt = p;
	}

	m_arrInt[m_iCount] = _iValue;

	++m_iCount;
}

int DynamicArray::Pop()
{
	if (1 > m_iCount) {
		cout << "배열이 비어있습니다." << endl;
		exit(1);
	}
	--m_iCount;

	return m_arrInt[m_iCount];
}