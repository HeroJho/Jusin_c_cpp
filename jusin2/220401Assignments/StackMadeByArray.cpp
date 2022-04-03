#include "pch.h"
#include "StackMadeByArray.h"

StackMadeByArray::StackMadeByArray()
{

}
StackMadeByArray::~StackMadeByArray()
{
}

void StackMadeByArray::Push(int _iValue)
{
	m_arr.Push(_iValue);
}

int StackMadeByArray::Pop()
{
	return m_arr.Pop();
}




