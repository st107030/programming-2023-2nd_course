#include <iostream>

template<typename T>
	struct Node
	{
		T data;
		Node* next;
		Node(T data, Node* next = nullptr) :
			data(data), next(next) {}
		~Node() {}
	};

template<typename T>
class List
{
private:
	Node* head;
	Node* tail;
	int Index_Valid(int index)
	{
		return (index % this->Length());
	}

public:
	List(Node* head, Node* tail)
	{
		this->head = head;
		this->tail = tail;
		this->tail->next = head;
	}
	~List()
	{
		while (this->head != nullptr)
		{
			Node temp = head;
			this->head = head->next;
			delete temp;
		}
	}
	void BiList::Insert_Node(Node* node) //insert to head
	{
		node->next = this->head;
		this->head = node;
		this->tail->next = this->head;
		return;
	} 
	int Length()
	{
		int count = 0;
		Node<T>* temp = this->head;
		count++;
		temp = temp->next;
		while (temp != head)
		{
			temp = temp->next;
			++count;
		}
		return count;
	}

	Node* Extract_Node(int index)//return pointer by index
	{
		index = Index_Valid(index));
		Node<T>* res = nullptr;
		if (index == 0)
		{
			res = this->head;
			this->head = this->head->next;
			this->tail = (this->head == nullptr ? nullptr : this->tail);
		}
		else
		{
			Node<T>* temp = this->head;
			while (index > 1)
			{
				temp = temp->next;
				--index;
			}
			res = temp->next;
			temp->next = temp->next->next;
		}
		return res;
	}
	void Remove(int index)
	{
		Node<T>* temp = this->Extract_Node(index);
		if (temp != nullptr)
		{
			delete temp;
		}
	}

	T& operator[](int index)
	{
		index = Index_Valid(index);
		Node<T>* temp = this->head;
		while (index > 0)
		{
			temp = temp->next;
			--index;
		}
		return temp->data;
	}

	friend std::ostream& operator<<(std::ostream& stream, const List& list);

	void Print(std::ostream& stream) const
	{
		Node<T>* temp = head;
		while (temp->next != head)
		{
			stream << temp->data << " ";
			temp = temp->next;
		}
		stream << temp->data;
	}
};

template <typename T>
std::ostream& operator<<(std::ostream& stream, const List<T>& list)
{
	list.Print(stream);
	return stream;
}

int main(int argc, char* argv[])
{
	//I will text smth here later
	return EXIT_SUCCESS;
}