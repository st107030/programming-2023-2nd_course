#include <Queue.h>

template <typename T>
class queue
{
private:
	mutex mut;
	struct Node
	{
		T data;
		Node* next;
		Node(T data, Node* next = NULL) : data(data), next(next) {}
	};

	Node* head = NULL;
	Node* tail = NULL;

public:
	queue(T x)
	{
		Node* temp = new Node;
		temp->data = x;
		mut.lock();
		if (!head)
		{
			head = temp;
			tail = temp;
			return;
		}
		tail->next = temp;
		tail = tail->next;
	}
	queue(const queue& q)
	{
		head = q.head;
		tail = q.tail;
	}
	queue() :head(NULL), tail(NULL) {}
	~queue()
	{
		mut.lock();
		while (head != NULL)
		{
			Node* temp = head;
			head = head->next;
			delete temp;
		}
		mut.unlock();
	}

	bool Empty()
	{
		if (head) return true;
		return false;
	}

	void Pop()
	{
		mut.lock();
		if (this->Empty()) throw ("Pop from empty queue.");
		Node* temp = head;
		head = head->next;
		if (head == NULL) tail = NULL;
		mut.unlock();
		delete temp;
	}

	int Front()
	{
		mut.lock();
		if (this->Empty()) throw ("The queue is empty. Impossible to select an element.");
		return head->data;
		mut.unlock();
	}
};