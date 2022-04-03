#pragma once

#include "Node.h"

class LinkedList
{
private:
	Node* m_pHead;
	Node* m_pTail;

public:
	void SetHead(Node* _pNode);
	Node* GetHead();

	void AddNode(Node* _pNode);

	void PrintList();

public:
	LinkedList();
	~LinkedList();

};

