#include <iostream>
using namespace std;

struct Node
{
	int value;
	Node* previous;

	Node(int v, Node* prev = nullptr)
	{
		value = v;
		previous = prev;
	}
};

class Stack
{
	Node* top = nullptr;

public:
	Stack()	{ }

	void push(int v)
	{
		if (!top)
		{
			top = new Node(v, top);
		}
		else
		{
			Node* newTop = new Node(v, top);
			top = newTop;
		}
	}

	int peek()
	{
		if (top)
		{
			return top->value;
		}
		else
		{
			throw underflow_error("Stack is empty");
		}
	}

	void pop()
	{
		if (top)
		{
			Node* oldTop = top;
			top = top->previous;
			delete oldTop;
		}
		else
		{
			throw underflow_error("Stack is empty");
		}
	}
};

int main()
{
	Stack s;

	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);

	cout << s.peek() << endl;

	s.pop();

	cout << s.peek() << endl;

	return 0;
}

