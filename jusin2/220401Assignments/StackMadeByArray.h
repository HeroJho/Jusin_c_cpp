#pragma once

#include "DynamicArray.h"

class StackMadeByArray
{
private:
	DynamicArray m_arr;

public:
	void Push(int _iValue);
	int Pop();
	int GetSize() { return m_arr.GetSize(); }

public:
	StackMadeByArray();
	~StackMadeByArray();

};

