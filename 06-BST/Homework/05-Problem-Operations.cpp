#include <iostream>
#include <queue>
using namespace std;

struct Node
{
	int data;
	Node* left;
	Node* right;


	Node(int data)
	{
		this->data = data;
		this->left = nullptr;
		this->right = nullptr;
	}
};

class BST
{
	Node* root;

	Node* _insert(int data, Node* curr)
	{
		if (!curr)
		{
			return new Node(data);
		}

		if (data < curr->data)
		{
			curr->left = _insert(data, curr->left);
		}
		else if (data > curr->data)
		{
			curr->right = _insert(data, curr->right);
		}

		return curr;
	}

	void _print(Node* curr)
	{
		if (curr)
		{
			cout << curr->data << " ";
			_print(curr->left);
			_print(curr->right);
		}
	}

	Node* _remove(Node* curr, int x)
	{
		if (!curr)
		{
			return nullptr;
		}

		if (x == curr->data)
		{
			if (!curr->left && !curr->right)
			{
				free(curr);
				return nullptr;
			}

			if (!curr->left)
			{
				Node* tmp = curr->right;
				free(curr);
				return tmp;
			}

			if (!curr->right)
			{
				Node* tmp = curr->left;
				free(curr);
				return tmp;
			}

			if (curr->right && curr->left)
			{
				Node* swapWith = curr->right;

				while (swapWith->left)
				{
					swapWith = swapWith->left;
				}

				curr->data = swapWith->data;
				curr->right = _remove(curr->right, swapWith->data);
			}
		}

		if (x < curr->data)
		{
			curr->left = _remove(curr->left, x);
		}

		if (x > curr->data)
		{
			curr->right = _remove(curr->right, x);
		}
	}

	void _printOddLayers(Node* root, bool isOdd = true)
	{
		if (root == NULL)
			return;

		if (isOdd)
			cout << root->data << " ";

		_printOddLayers(root->left, !isOdd);
		_printOddLayers(root->right, !isOdd);
	}

public:
	BST()
	{
		this->root = nullptr;
	}

	void insert(int x)
	{
		this->root = _insert(x, this->root);
	}

	void print()
	{
		_print(this->root);
	}

	void remove(int x)
	{
		this->root = _remove(this->root, x);
	}

	void printOddLayers()
	{
		_printOddLayers(this->root);
	}
};

int main()
{
    int countOperations;
    cin >> countOperations;

	BST tree;

	for (int i = 0; i < countOperations; i++)
	{
		string command;
		cin >> command;

		if (command == "add")
		{
			int num;
			cin >> num;

			tree.insert(num);
		}
		else if (command == "print")
		{
			tree.print();
		}
		else if (command == "remove")
		{
			int num;
			cin >> num;

			tree.remove(num);
		}
		else
		{
			tree.printOddLayers();
		}
	}
	return 0;
}
