#include <iostream>
#include <fstream>
#include <thread>

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
            Node* temp = head;
            head = head->next;
            delete temp;
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
        {
            return;
        }

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

void test1()
{
    List<int> list1;
    list1.Insert(100);
    list1.Insert(200);
    list1.Insert(300);
    std::cout << "int" << std::endl;
    std::cout << list1.Count() << std::endl;
    std::cout << list1[0] << std::endl;
    list1.RemoveNode(0);
    list1.Print();
    std::cout << std::endl << std::endl;
}

void test2()
{
    List<char> list2;
    list2.Insert('a');
    list2.Insert('b');
    list2.Insert('c');
    std::cout << "char" << std::endl;
    std::cout << list2.Count() << std::endl;
    std::cout << list2[0] << std::endl;
    list2.RemoveNode(0);
    list2.Print();
    std::cout << std::endl << std::endl;
}

void test3()
{
    List<double> list3;
    list3.Insert(0.2);
    list3.Insert(7.1);
    list3.Insert(3.3);
    std::cout << "double" << std::endl;
    std::cout << list3.Count() << std::endl;
    std::cout << list3[0] << std::endl;
    list3.RemoveNode(0);
    list3.Print();
    std::cout << std::endl;
}

int main()
{
    test1();
    test2();
    test3();
    return EXIT_SUCCESS;
}