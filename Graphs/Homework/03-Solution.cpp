#include <iostream>
#include <queue>
using namespace std;

struct Node
{
    int value;
    Node* left;
    Node* right;

    Node(int value)
    {
        this->value = value;
        this->left = nullptr;
        this->right = nullptr;
    }
};

class BST
{
    Node* root;

    Node* _insert(Node* curr, int value)
    {
        if (!curr)
        {
            return new Node(value);
        }

        if (value < curr->value)
        {
            curr->left = _insert(curr->left, value);
        }
        else if (value > curr->value)
        {
            curr->right = _insert(curr->right, value);
        }

        return curr;
    }

    void _print(Node* root)
    {
        if (!root)
        {
            return;
        }

        queue<Node*> que;
        que.push(root);

        while (!que.empty())
        {
            // count nodes at curr level
            int n = que.size();

            for (int i = 1; i <= n; i++)
            {
                Node* tmp = que.front();
                que.pop();

                if (i == 1)
                {
                    cout << tmp->value << " ";
                }

                if (tmp->left != nullptr)
                {
                    que.push(tmp->left);
                }

                if (tmp->right != nullptr)
                {
                    que.push(tmp->right);
                }
            }
        }
    }

public:
    BST()
    {
        this->root = nullptr;
    }

    void insert(int value)
    {
        this->root = _insert(root, value);
    }

    void print()
    {
        _print(root);
    }
};

int main()
{
    int n;
    int value;
    cin >> n;

    BST tree;

    for (int i = 0; i < n; i++) {
        cin >> value;
        tree.insert(value);
    }

    tree.print();
}
