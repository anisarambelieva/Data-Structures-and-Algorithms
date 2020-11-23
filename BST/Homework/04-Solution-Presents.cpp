#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node
{
	int data; // the index of the employee
	// all the employees below this "boss"
	vector<Node*> employees;

	Node(int data)
	{
		this->data = data;
	}
};

class Tree
{
private:
	Node* root;

	void _insert(int x, int y)
	{
		// x is the boss, y - the new employee
		Node* boss = findNode(x, root);

		Node* emplToAdd = new Node(y);
		if (boss)
		{
			boss->employees.push_back(emplToAdd);
		}
	}

	Node* findNode(int data, Node* root)
	{
		if (data == 0)
		{
			return root;
		}

		Node* curr = root;

		int employeesCount = root->employees.size();

		for (int i = 0; i < employeesCount; i++)
		{
			Node* currEmployee = root->employees[i];
			if (currEmployee->data == data)
			{
				return currEmployee;
			}
		}

		for (int i = 0; i < employeesCount; i++)
		{
			Node* currEmployee = root->employees[i];
			Node* found = findNode(data, currEmployee);
			if (found)
			{
				return found;
			}
		}
	}

	int _countOfEmployees(Node* root, int boss)
	{
		if (!root)
		{
			return 0;
		}

		int count = 0;
		queue<Node*> q;
		q.push(root);

		while (!q.empty())
		{
			int n = q.size();

			// if this boss has employees
			while (n > 0)
			{
				Node* p = q.front();
				q.pop();

				if (p->data == boss)
				{
					count += p->employees.size();
					for (int i = 0; i < p->employees.size(); i++)
					{
						count += _countOfEmployees(p, p->employees[i]->data);
					}
					return count;
				}

				for (int i = 0; i < p->employees.size(); i++)
				{
					q.push(p->employees[i]);
				}
				n--;
			}
		}
		return count;
	}

public:
	Tree()
	{
		// add the "CEO" == root of the tree
		this->root = new Node(0);
	}

	void insert(int boss, int employee)
	{
		_insert(boss, employee);
	}

	int countOfEmployees(int boss)
	{
		return _countOfEmployees(root, boss);
	}
};

int main()
{
    int countEmployees;
    cin >> countEmployees;

	Tree organization;

	for (int i = 1; i < countEmployees; i++)
	{
		int x, y;
		cin >> x >> y;

		organization.insert(x, y);
	}

	for (int i = 0; i < countEmployees; i++)
	{
		int count = organization.countOfEmployees(i);
		cout << count << " ";
	}
}
