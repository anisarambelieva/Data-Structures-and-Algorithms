#include <iostream>
#include <climits>
#include <list>
using namespace std;

class Stack 
{
private:
    list<int> data;
    list<int> minElements;
    int minElement = INT_MAX;

public:
    void push(int number) 
    {
        if (isEmpty())
        {
            minElement = INT_MAX;
        }
        if (number < minElement)
        {
            minElement = number;
        }
        minElements.push_back(minElement);
        data.push_back(number);
    }

    void pop() 
    {
        data.pop_back();
        minElements.pop_back();
        minElement = minElements.back();
    }

    int peek() const 
    {
        return data.back();
    }

    bool isEmpty()
    {
        return data.size() == 0;
    }

    int findMin()
    {
        return minElements.back();
    }
};

int main()
{
    Stack stack;

    int countQ;
    cin >> countQ;

    for (int i = 0; i < countQ; i++)
    {
        string query;
        cin >> query;

        if (query == "push")
        {
            int x;
            cin >> x;
            stack.push(x);
        }
        else if (query == "pop")
        {
            stack.pop();
        }
        else if (query == "peek")
        {
            cout << stack.peek() << endl;
        }
        else if (query == "min")
        {
            cout << stack.findMin() << endl;
        }
    }
    return 0;
}