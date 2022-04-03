#pragma once

#include "DNode.h"

class DListedList
{
private:
	DNode* m_pHead;
	DNode* m_pTail;

public:
	void SetHead(DNode* _pNode);
	DNode* GetHead();
	DNode* GetTail();

	void AddNode(DNode* _pNode);

	void PrintList();

public:
	DListedList();
	~DListedList();

};

