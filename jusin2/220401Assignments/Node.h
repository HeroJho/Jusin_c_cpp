#pragma once
class Node
{
private:
	int		m_iData;
	Node*	m_pNext;

public:
	void SetNext(Node* _pNode);
	void SetData(int _iValue);
	
	Node* GetNext();
	int GetData();

public:
	Node(int _iData);
	~Node();

};

