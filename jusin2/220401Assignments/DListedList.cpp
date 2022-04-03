#include "pch.h"
#include "DListedList.h"

DListedList::DListedList()
	: m_pHead(nullptr)
	, m_pTail(nullptr)
{
}

DListedList::~DListedList()
{
	SAVE_DELETE(m_pHead)
}

void DListedList::SetHead(DNode* _pNode)
{
	m_pTail = _pNode;
	m_pHead = _pNode;
}

DNode* DListedList::GetHead()
{
	return m_pHead;
}

DNode* DListedList::GetTail()
{
	return m_pTail;
}

void DListedList::AddNode(DNode* _pNode)
{
	if (m_pTail == nullptr)
	{
		SetHead(_pNode);
		return;
	}

	// け <-> け -> し
	m_pTail->SetNext(_pNode);
	// け <-> け <-> し
	m_pTail->GetNext()->SetPre(m_pTail);

	m_pTail = _pNode;
}

void DListedList::PrintList()
{
	cout << "Head To Tail" << endl;
	for (DNode* n = m_pHead; n != nullptr; n = n->GetNext())
	{
		cout << n->GetData() << endl;
	}
	cout << "Tail To Head" << endl;
	for (DNode* n = m_pTail; n != nullptr; n = n->GetPre())
	{
		cout << n->GetData() << endl;
	}
}