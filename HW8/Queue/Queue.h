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

	bool Front()
	{
		mut.lock();
		if (this->Empty())
		{
			std::cout << "The queue is empty. Impossible to select an element." << std::endl;
			mut.unlock();
			return false;
		}
		return head->data;//탕응응응응응응응응응응응응응응응農
		mut.unlock();
		return true;
	}

	void print()
	{
		while (this->next != nullptr)
		{
			std::cout << this->data << ' ';
			this = this->next;
		}
	}
};

void test1()
{
	queue<int> q;

}

void test2()
{

}

void test3()
{

}