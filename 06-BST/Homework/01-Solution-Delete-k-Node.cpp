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
private:
    Node* root;
    int kthElement;

    Node* _insert(int data, Node* curr)
    {
        if (curr == nullptr)
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
    Node* _remove(int data, Node* curr)
    {
        if (!curr)
        {
            return nullptr;
        }

        if (data < curr->data)
        {
            curr->left = _remove(data, curr->left);
        }
        else if (data > curr->data)
        {
            curr->right = _remove(data, curr->right);
        }
        else
        {
            // curr->data == data
            if (!curr->left && !curr->right)
            {
                // curr has no child nodes
                // Simply remove from the tree

                free(curr);
                return nullptr;
            }
            else if (!curr->left)
            {
                // curr has only a right child node
                // Copy the child to the node and delete the child
                Node* rightTmp = curr->right;
                free(curr);
                return rightTmp;
            }
            else if (!curr->right)
            {
                Node* leftTmp = curr->left;
                free(curr);
                return leftTmp;
            }
            else
            {
                Node* swapWith = curr->right;
                while (swapWith->left) {
                    swapWith = swapWith->left;
                }

                curr->data = swapWith->data;
                curr->right = _remove(swapWith->data, curr->right);
            }
        }
        return curr;
    }

    void _findKthElement(Node* curr, int k, int &c)
    {
        if (curr == nullptr || c >= k)
        {
            return;
        }

        _findKthElement(curr->right, k, c);

        c++;

        // if c becomes k now, then this is the k'th largest 
        if (k == c)
        {
            // cout << k << "th element is " << curr->data << endl;
            this->kthElement = curr->data;
            return;
        }

        _findKthElement(curr->left, k, c);
    }

    //void findKthElement(Node* root, )

    void _removeKthElement(Node* curr, int k)
    {
        // find the element
        int c = 0;

        _findKthElement(curr, k, c);

        curr = _remove(this->kthElement, curr);
    }

    void printLevelOrder(Node* root)
    {
        if (root == NULL)
        {
            return;
        }

        queue<Node*> q;

        q.push(root);

        while (q.empty() == false)
        {
            Node* node = q.front();
            cout << node->data << " ";
            q.pop();

            if (node->left != NULL)
                q.push(node->left);

            if (node->right != NULL)
                q.push(node->right);
        }
    }

public:
    BST()
    {
        this->root = nullptr;
    }

    void insert(int data)
    {
        root = _insert(data, root);
    }

    void removeKthElement(int k)
    {
        _removeKthElement(root, k);
    }

    void lvlPrint()
    {
        printLevelOrder(root);
    }
};

int main()
{
    BST tree;

    int countElements, k;
    cin >> countElements >> k;

    for (int i = 0; i < countElements; i++)
    {
        int element;
        cin >> element;

        tree.insert(element);
    }

    tree.removeKthElement(k);

    // print every level

    tree.lvlPrint();
    return 0;
}
