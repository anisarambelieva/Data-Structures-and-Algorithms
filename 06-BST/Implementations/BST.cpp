#include <iostream>
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

    ~Node()
    {
        delete this->left;
        delete this->right;
    }

    Node(const Node& rhs) {
        data = rhs.data;
        if (rhs.left) {
            left = new Node(*rhs.left);
        }
        if (rhs.right) {
            right = new Node(*rhs.right);
        }
    }

    Node& operator=(const Node& rhs) {
        if (this != &rhs) {
            delete left;
            delete right;

            data = rhs.data;
            if (rhs.left) {
                left = new Node(*rhs.left);
            }
            if (rhs.right) {
                right = new Node(*rhs.right);
            }
        }
        return *this;
    }
};

class BST
{
private: 
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


    void _inorder(Node* curr) const
    {
        if (curr)
        {
            _inorder(curr->left);
            cout << curr->data << " ";
            _inorder(curr->right);
        }
    }

    void _preorder(Node* curr) const
    {
        if (curr)
        {
            cout << curr->data << " ";
            _preorder(curr->left);
            _preorder(curr->right);
        }
    }

    void _postorder(Node* curr) const
    {
        if (curr)
        {
            //left, right, root
            _postorder(curr->left);
            _postorder(curr->right);
            cout << curr->data << " ";
        }
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

public:

    BST()
    {
        this->root = nullptr;
    }

    void insert(int data)
    {
        root = _insert(data, root);
    }

    void inorder()
    {
        _inorder(root);
    }

    void preorder()
    {
        _preorder(root);
    }

    void postorder()
    {
        _postorder(root);
    }

    void remove(int data)
    {
        root = _remove(data, root);
    }
};

int main()
{
    BST tree;
    tree.insert(3);
    tree.insert(1);
    tree.insert(4);
    tree.insert(2);
    tree.insert(5);

    tree.inorder();
    cout << endl;
    tree.remove(5); //works
    tree.inorder();

}
