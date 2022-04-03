#pragma once


class DNode
{
private:
	int		m_iData;
	DNode*  m_pNext;
	DNode*	m_pPre;

public:
	void SetNext(DNode* _pNode);
	void SetPre(DNode* _pNode);
	void SetData(int _iValue);

	DNode* GetNext();
	DNode* GetPre();
	int GetData();

public:
	DNode(int _iData);
	~DNode();

};

