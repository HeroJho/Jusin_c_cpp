#include "pch.h"
#include "LinkedList.h"

LinkedList::LinkedList()
	: m_pHead(nullptr)
	, m_pTail(nullptr)
{
}

LinkedList::~LinkedList()
{
	SAVE_DELETE(m_pHead)
}

void LinkedList::SetHead(Node* _pNode)
{
	m_pTail = _pNode;
	m_pHead = _pNode;
}

Node* LinkedList::GetHead()
{
	return m_pHead;
}

void LinkedList::AddNode(Node* _pNode)
{
	if (m_pTail == nullptr)
	{
		SetHead(_pNode);
		return;
	}

	m_pTail->SetNext(_pNode);
	m_pTail = _pNode;
}

void LinkedList::PrintList()
{
	for (Node* n = m_pHead; n != nullptr; n = n->GetNext())
	{
		cout << n->GetData() << endl;
	}
}
