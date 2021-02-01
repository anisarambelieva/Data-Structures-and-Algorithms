#include <iostream>
#include <string>
using namespace std;

struct Node
{
    int value;
    Node* next;

    Node(int v)
    {
        this->value = v;
        this->next = nullptr;
    }
};

class LinkedList
{
    Node* head;
    Node* tail;
public:
    LinkedList()
    {
        this->head = nullptr;
        this->tail = nullptr;
    }

    void add(int v)
    {
        if (head == nullptr)
        {
            this->head = new Node(v);
            this->tail = this->head;
        }
        else
        {
            this->tail->next = new Node(v);
            this->tail = this->tail->next;
        }
    }

    int min()
    {
        int result = INT_MAX;

        Node* curr = this->head;
        int currValue;

        while (curr)
        {
            currValue = curr->value;

            if (currValue < result)
            {
                result = currValue;
            }
            curr = curr->next;
        }

        return result;
    }

    int max()
    {
        int result = INT_MIN;

        Node* curr = this->head;
        int currValue;

        while (curr)
        {
            currValue = curr->value;

            if (currValue > result)
            {
                result = currValue;
            }
            curr = curr->next;
        }
        return result;
    }

    int sum()
    {
        int result = 0;

        Node* curr = this->head;
        int currValue;

        while (curr)
        {
            currValue = curr->value;
            result += currValue;
            curr = curr->next;
        }

        return result;
    }
};

int main()
{
    int count;
    cin >> count;
    LinkedList ll;

    int num;

    for (int i = 0; i < count; i++)
    {
        cin >> num;
        ll.add(num);
    }

    cout << ll.min() << " " << ll.max() << " " << ll.sum();
}
