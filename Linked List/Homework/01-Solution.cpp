#include <iostream>
#include <vector>
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
        if (!this->head)
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

    int checkPairs(int x, int y)
    {
        int count = 0;

        Node* curr = head;
        Node* next = head->next;

        while (curr->next)
        {
            if (curr->value == x && next->value == y)
            {
                count++;
            }

            curr = next;
            next = curr->next;
        }

        return count;
    }
};

int main()
{
    int countN;
    cin >> countN;

    int num;

    LinkedList ll;

    for (int i = 0; i < countN; i++)
    {
        cin >> num;
        ll.add(num);
    }

    int countP;
    cin >> countP;

    vector<int> numbers;

    int curr;

    for (int i = 0; i < countP; i++)
    {
        cin >> curr;
        numbers.push_back(curr);
    }

    int result = 0;

    for (int i = 0; i < countP-1; i++)
    {
        int x = numbers[i];
        int y = numbers[i + 1];

        result += ll.checkPairs(x, y);
    }

    cout << result;
    return 0;
}

