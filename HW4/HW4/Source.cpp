#include <iostream>

template <typename T>

class List
{
private:
    struct  Node
    {
        T data;
        Node* next;
    };

    Node* head;
    Node* tail;
    int size;
public:
    List() :head(NULL), tail(NULL), size(0) {};
    ~List()
    {
        while (size != 0) 
        {
            Node* temp = head->next;
            delete head; 
            head = temp; 
            size--;
        }
    }

    int Count()
    {
        return size; 

    }

    void Insert(T x)
    {
        size++;
        Node* temp = new Node; 
        temp->next = head; 
        temp->data = x; 
        if (head != NULL) 
        {
            tail->next = temp;
            tail = temp; 
        }
        else head = tail = temp;
    }

    T& operator[](int index) 
    {
        index %= size;
        Node* current = head;
        for (int i = 0; i < index && current != nullptr; i++)
            current = current->next;
        return current->data;
    }

    void RemoveNode(int index)
    {
        index %= size;
        if (head == nullptr) 
        { return; }

        Node* current = head;

        if (current->next == head && index == 0) 
        {
            head = nullptr;
            delete current;
            size--;
            return;
        }

        if (index == 0)
        {
            Node* temp = head;
            head = head->next;
            tail->next = head;
            delete temp;
            size--;
        }
        else
        {
            int count = 0;
            while (count != index - 1)
            {
                current = current->next;
                count++;
            }
            Node* temp = current->next;
            current->next = current->next->next;
            delete temp;
            size--;
        }
    }

    void Print()
    {
        Node* tmph;
        tmph = head; 
        int temp = size;
        while (temp != 0)
        {
            std::cout << tmph->data << " "; 
            tmph = tmph->next; 
            temp--; 
        }
    }
};

int main()
{
    List<int> list;
    list.Insert(100);
    list.Insert(200);
    list.Insert(300);

    list.Print(); 
    std::cout << std::endl;

    list.RemoveNode(0);
    list.Print();
    return EXIT_SUCCESS;
}