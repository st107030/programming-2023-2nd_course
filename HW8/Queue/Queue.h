#pragma once

template <typename T>
class queue
{
private:
	std::mutex mut;
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
		Node* temp = new Node(x);
		mut.lock();
		if (!head)
		{
			head = temp;
			tail = temp;
			mut.unlock();
			return;
		}
		tail->next = temp;
		tail = tail->next;
		mut.unlock();
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
		if (head == nullptr) return true;
		return false;
	}

	bool Pop()
	{
		mut.lock();
		if (this->Empty())
		{
			std::cout << "Pop from empty queue." << std::endl;
			mut.unlock();
			return false;
		}
		Node* temp = head;
		head = head->next;
		if (head == NULL) tail = NULL;
		mut.unlock();
		delete temp;
		return true;
	}

	bool Front(T &t)
	{
		mut.lock();
		if (this->Empty())
		{
			std::cout << "The queue is empty. Impossible to select an element." << std::endl;
			mut.unlock();
			return false;
		}
		t = head->data;
		mut.unlock();
		return true;
	}

	void Insert(T x)
	{
		Node* temp = new Node(x);
		mut.lock();
		tail->next = temp;
		temp->next = nullptr;
		tail = temp;
		mut.unlock();
	}


	void print()
	{
		mut.lock();
		Node* q = head;
		while (q->next != nullptr)
		{
			std::cout << q->data << ' ';
			q = q->next;
		}
		std::cout << q->data << std::endl;
		mut.unlock();
	}
};

void test1(queue<int>& q)
{
	q.Insert(2);
	q.print();
	q.Insert(3);
	q.print();
}

void test2(queue<int>& q)
{
	q.Pop();
	q.print();
}

void test3(queue<int>& q)
{
	int x = 0;
	std::cout << "Front " << q.Front(x) << std::endl;
}