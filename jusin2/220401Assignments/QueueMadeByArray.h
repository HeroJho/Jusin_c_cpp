#pragma once

#include "DynamicArray.h"

class QueueMadeByArray
{
protected:
	DynamicArray m_arr;

public:
	void Push(int _iValue);
	int Pop();
	int GetSize() { return m_arr.GetSize(); }

public:
	QueueMadeByArray();
	~QueueMadeByArray();
};

