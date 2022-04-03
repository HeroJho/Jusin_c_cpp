#include "pch.h"
#include "StackMadeByArray.h"
#include "QueueMadeByArray.h"
#include "DequeueMadeByArray.h"
#include "LinkedList.h"
#include "DListedList.h"

int main()
{
	cout << "=======Stack=======" << endl;
	StackMadeByArray s;
	s.Push(10);
	s.Push(20);
	s.Push(30);
	s.Push(40);
	s.Push(50);
	s.Push(60);

	int size = s.GetSize();
	for (int i = 0; i < size; ++i)
		cout << s.Pop() << endl;
	cout << endl;


	cout << "=======Queue=======" << endl;
	QueueMadeByArray q;
	q.Push(10);
	q.Push(20);
	q.Push(30);
	q.Push(40);
	q.Push(50);
	q.Push(60);

	size = q.GetSize();
	for (int i = 0; i < size; ++i)
		cout << q.Pop() << endl;
	cout << endl;


	cout << "=======Dequeue=======" << endl;
	DequeueMadeByArray qq;
	qq.Push_Front(30);
	qq.Push_Front(20);
	qq.Push_Front(10);
	qq.Push_Back(40);
	qq.Push_Back(50);
	qq.Push_Back(60);

	size = qq.GetSize();
	for (int i = 0; i < size; ++i) {
		if(i%2 == 0)
			cout << qq.Pop_Front() << endl;
		else
			cout << qq.Pop_Back() << endl;
	}
	cout << endl;


	cout << "=======LinkedList=======" << endl;
	LinkedList ll;
	ll.AddNode(new Node(10));
	ll.AddNode(new Node(20));
	ll.AddNode(new Node(30));
	ll.AddNode(new Node(40));
	ll.AddNode(new Node(50));
	ll.AddNode(new Node(60));
	
	for (Node* n = ll.GetHead(); n != nullptr; n = n->GetNext())
		cout << n->GetData() << endl;
	cout << endl;


	cout << "=======DoubleLinkedList=======" << endl;
	DListedList Dll;
	Dll.AddNode(new DNode(10));
	Dll.AddNode(new DNode(20));
	Dll.AddNode(new DNode(30));
	Dll.AddNode(new DNode(40));
	Dll.AddNode(new DNode(50));
	Dll.AddNode(new DNode(60));

	cout << "[Head To Tail]" << endl;
	for (DNode* n = Dll.GetHead(); n != nullptr; n = n->GetNext())
		cout << n->GetData() << endl;
	cout << "[Tail To Head]" << endl;
	for (DNode* n = Dll.GetTail(); n != nullptr; n = n->GetPre())
		cout << n->GetData() << endl;
	cout << endl;
}
