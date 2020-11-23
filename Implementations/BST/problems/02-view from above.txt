#include <iostream>
#include <queue>
#include <map>
using namespace std;

struct Node
{
	int data;
	Node* left;
	Node* right;
	int hd; // horizontal distance

	Node(int data)
	{
		this->data = data;
		this->left = nullptr;
		this->right = nullptr;
	}
};

class BST
{
private:
	Node* root;

	// when inserting where to insert
	// i - this is the current level we have to add to
	void _insert(int leftChild, int rightChild, Node* root, int i)
	{
		// if i == 0 then we add to the root
		// if i == 1 then we add to the node with data 1 and so on
		// if one of the child nodes == -1 then we don't add the child

		Node* toAddChildren = findNode(i, root);

		if (leftChild != -1)
		{
			Node* left = new Node(leftChild);
			toAddChildren->left = left;
		}
		if (rightChild != -1)
		{
			Node* right = new Node(rightChild);
			toAddChildren->right = right;
		}
	}

	Node* findNode(int data, Node* root)
	{
		Node* curr = root;

		if (curr->data == data)
		{
			return curr;
		}
		if (curr->left)
		{
			Node* copyLeft = curr->left;
			copyLeft = findNode(data, curr->left);
			if (copyLeft != nullptr)
			{
				return copyLeft;
			}
		}
		if (curr->right)
		{
			Node* copyRight = curr->right;
			copyRight = findNode(data, curr->right);
			if (copyRight != nullptr)
			{
				return copyRight;
			}
		}
		return nullptr;
	}

	void _viewFromAbove(Node* root)
	{
		if (root == nullptr)
		{
			return;
		}

		queue<Node*> q;
		map<int, int> m;

		int hd = 0;
		root->hd = 0;

		q.push(root);

		while (q.size())
		{
			hd = root->hd;

			if (m.count(hd) == 0)
			{
				m[hd] = root->data;
			}

			if (root->left)
			{
				root->left->hd = hd - 1;
				q.push(root->left);
			}
			if (root->right)
			{
				root->right->hd = hd + 1;
				q.push(root->right);
			}
			q.pop();
			if (q.size() != 0)
			{
				root = q.front();
			}
		}

		for (auto i = m.begin(); i != m.end(); i++)
		{
			cout << i->second << " ";
		}
	}

public:
	BST()
	{
		Node* root = new Node(0);
		this->root = root;
	}

	void insert(int leftChild, int rightChild, int i)
	{
		_insert(leftChild, rightChild, root, i);
	}

	void viewFromAbove()
	{
		_viewFromAbove(root);
	}
};

int main()
{
	int count;
	cin >> count;

	BST tree;

	for (int i = 0; i < count; i++)
	{
		int left, right;
		cin >> left >> right;
		tree.insert(left, right, i);
	}

	tree.viewFromAbove();
}
