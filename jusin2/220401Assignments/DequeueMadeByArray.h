#pragma once

#include "QueueMadeByArray.h"

class DequeueMadeByArray 
	: public QueueMadeByArray
{
private:

public:
	int Pop_Front();
	int Pop_Back();

	void Push_Front(int _iValue);
	void Push_Back(int _iValue);

public:
	DequeueMadeByArray();
	~DequeueMadeByArray();

};

