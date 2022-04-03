#include "pch.h"
#include "Node.h"

Node::Node(int _iData)
	: m_pNext(nullptr)
	, m_iData(_iData)
{
}

Node::~Node()
{
	SAVE_DELETE(m_pNext)
}

void Node::SetNext(Node* _pNode)
{
	m_pNext = _pNode;
}

void Node::SetData(int _iValue)
{
	m_iData = _iValue;
}

Node* Node::GetNext()
{
	return m_pNext;
}

int Node::GetData()
{
	return m_iData;
}
