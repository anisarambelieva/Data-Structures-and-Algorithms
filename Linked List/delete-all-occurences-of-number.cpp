#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;

    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

class LinkedList
{
public:
    Node* head;

    void insert(int data)
    {
        Node* toInsert = new Node(data);

        if (this->head == nullptr)
        {
            head = toInsert;
        }
        else
        {
            Node* curr = this->head;
            while (curr->next)
            {
                curr = curr->next;
            }
            curr->next = toInsert;
        }
    }

    void print()
    {
        Node* curr = this->head;

        while (curr)
        {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
    }

    void deleteAll(int number)
    {
        Node* curr = this->head->next;
        Node* prev = this->head;

        if (head->data == number)
        {
            head = head->next;
        }

        while (curr)
        {
            if (curr->data == number)
            {
                prev->next = curr->next;
                curr = curr->next;
            }
            else
            {
                curr = curr->next;
                prev = prev->next;
            }
        }
    }
};

int main()
{
    LinkedList* myList = new LinkedList();
    myList->insert(2);
    myList->insert(1);
    myList->insert(2);
    myList->insert(3);
    myList->insert(2);
    myList->insert(5);

    myList->print();

    myList->deleteAll(2);

    myList->print();
}
