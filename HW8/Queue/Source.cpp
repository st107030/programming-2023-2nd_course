#include <iostream>

template <typename T>
class queue
{
	class Node
	{
		T data;
		Node* next;
		Node(T data, Node* next = NULL): data(data), next(next)
	};

	Node* head = NULL;
	Node* tail = NULL;
};