#include <iostream>
using namespace std;

#define max(a, b) ((a) > (b) ? (a) : (b))

void swap(int& a, int& b) 
{
    int tmp = a;
    a = b;
    b = tmp;
}

struct Node
{
    int value;
    Node* left = nullptr;
    Node* right = nullptr;
    int weight = 0;

    Node() = default;

    Node(int value)
    {
        this->value = value;
    }

    ~Node()
    {
        delete this->left;
        delete this->right;
    }

    void calcWeight()
    {
        weight = 0;
        if (this->left)
        {
            weight = max(weight, this->left->weight + 1);
        }
        if (this->right)
        {
            weight = max(weight, this->right->weight + 1);
        }
    }

    int leftWeight() const {
        if (left) {
            return left->weight + 1;
        }
        return 0;
    }

    int rightWeight() const {
        if (right) {
            return right->weight + 1;
        }
        return 0;
    }

    int balance() const 
    {
        return leftWeight() - rightWeight();
    }

    void rotateRight()
    {
        if (!this->left)
        {
            return;
        }

        Node* leftRight = this->left->right;
        Node* oldRight = this->right;

        swap(this->value, this->left->value);

        this->right = this->left;
        this->left = this->left->left;
        this->right->left = leftRight;
        this->right->right = oldRight;
    }

    void rotateLeft() 
    {
        if (!right) 
        {
            return;
        }

        Node* rightLeft = this->right->left;
        Node* oldLeft = this->left;

        swap(this->value, this->right->value);

        this->left = this->right;
        this->right = this->right->right;
        this->left->left = oldLeft;
        this->left->right = rightLeft;
    }

    void recalculateWeights() 
    {
        if (left) 
        {
            left->calcWeight();
        }
        if (right)
        {
            right->calcWeight();
        }

        this->calcWeight();
    }

    void fixTree()
    {
        if (balance() < -1) // right is heavier
        {
            if (right->balance() <= -1) // right right
            {
                this->rotateLeft();
                recalculateWeights();
            }
            else if (right->balance() >= 1) // RL
            {
                right->rotateRight();
                this->rotateLeft();
                recalculateWeights();
            }
        }
        else if (balance() > 1) // Left is heavier
        { 
            if (left->balance() >= 1) // LL
            { 
                this->rotateRight();
                recalculateWeights();
            }
            else if (left->balance() <= -1) // LR
            { 
                left->rotateLeft();
                this->rotateRight();
                recalculateWeights();
            }
        }
    }
};

class BST
{
private:
    Node* root;

    Node* _insert(int value, Node* curr)
    {
        if (!curr)
        {
            return new Node(value);
        }
        if (value < curr->value)
        {
            curr->left = _insert(value, curr->left);
        }
        else if (value > curr->value)
        {
            curr->right = _insert(value, curr->right);
        }

        curr->calcWeight();
        curr->fixTree();
        return curr;
    }

    Node* _remove(int value, Node* curr)
    {
        if (!curr)
        {
            return nullptr;
        }

        if (value < curr->value)
        {
            curr->left = _remove(value, curr->left);
        }
        else if (value > curr->value)
        {
            curr->right = _remove(value, curr->right);
        }
        else // value == curr->value
        {
            if (!curr->left && !curr->right) // we have to delete a leaf
            {
                free(curr);
                return nullptr;
            }
            else if (!curr->left) // curr has only a right child
            {
                Node* tmpRight = curr->right;
                free(curr);
                return tmpRight;
            }
            else if (!curr->right)
            {
                Node* tmpLeft = curr->left;
                free(curr);
                return tmpLeft;
            }
            else // curr has both child nodes
            {
                // find the node that we can replace the one to delete with
                Node* swapWith = curr->right;
                while (swapWith->left)
                {
                    swapWith = swapWith->left;
                }
                curr->value = swapWith->value;
                curr->right = _remove(swapWith->value, curr->right);
            }
        }
        curr->calcWeight();
        curr->fixTree();
        return curr;
    }

    void _inorder(Node* curr) const 
    {
        if (curr)
        {
            _inorder(curr->left);
            cout << curr->value << " ";
            _inorder(curr->right);
        }
    }


public:
    void deleteNode(int value)
    {
        root = _remove(value, root);
    }

    void insertNode(int value)
    {
        root = _insert(value, root);
    }

    void inorderTraversal()
    {
        _inorder(root);
    }
};

int main()
{
    int n;
    cin >> n;

    BST* tree = new BST();

    for (int i = 0; i < n; i++)
    {
        string command;
        cin >> command;

        if (command == "add")
        {
            int value;
            cin >> value;
            tree->insertNode(value);
        }
        else if (command == "del")
        {
            int value;
            cin >> value;
            tree->deleteNode(value);
        }
        else if (command == "inorder")
        {
            tree->inorderTraversal();
            cout << endl;
        }
    }
    return 0;
}
