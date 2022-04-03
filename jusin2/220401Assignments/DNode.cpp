#include "pch.h"
#include "DNode.h"

DNode::DNode(int _iData)
	: m_pNext(nullptr)
	, m_pPre(nullptr)
	, m_iData(_iData)
{
}

DNode::~DNode()
{
	SAVE_DELETE(m_pNext)
}

void DNode::SetNext(DNode* _pNode)
{
	m_pNext = _pNode;
}

void DNode::SetPre(DNode* _pNode)
{
	m_pPre = _pNode;
}

void DNode::SetData(int _iValue)
{
	m_iData = _iValue;
}

DNode* DNode::GetNext()
{
	return m_pNext;
}

DNode* DNode::GetPre()
{
	return m_pPre;
}

int DNode::GetData()
{
	return m_iData;
}
