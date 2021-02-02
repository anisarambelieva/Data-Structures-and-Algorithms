#include <iostream>
using namespace std;

void swap(int& a, int& b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

struct Node
{
    int value;
    int height;

    Node* left;
    Node* right;

    Node(int v)
    {
        value = v;
        height = 0;
        left = nullptr;
        right = nullptr;
    }

    void calculateHeight()
    {
        height = 0;

        if (left)
        {
            height = max(height, left->height + 1);
        }

        if (right)
        {
            height = max(height, right->height + 1);
        }
    }

    int leftHeight() const
    {
        if (left)
        {
            return left->height + 1;
        }
        return 0;
    }

    int rightHeight() const
    {
        if (right)
        {
            return right->height + 1;
        }
        return 0;
    }

    int balance() const
    {
        return leftHeight() - rightHeight();
    }

    void rotateRight()
    {
        if (!left)
        {
            return;
        }

        Node* oldRight = this->right;
        Node* leftRight = this->left->right;

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

        Node* oldLeft = this->left;
        Node* rightLeft = this->right->left;

        swap(this->value, this->right->value);

        this->left = this->right;
        this->right = this->right->right;
        this->left->left = oldLeft;
        this->left->right = rightLeft;
    }

    void recalculateHeights()
    {
        if (left)
        {
            left->calculateHeight();
        }
        if (right)
        {
            right->calculateHeight();
        }
        this->calculateHeight();
    }

    void fixTree()
    {
        if (balance() < -1) // Right is heavier
        {
            if (right->balance() <= -1) //RR
            {
                this->rotateLeft();
                recalculateHeights();
            }
            else if (right->balance() >= 1) //RL
            {
                right->rotateRight();
                this->rotateLeft();
                recalculateHeights();
            }
        }
        else if (balance() > 1) // Left is heavier
        {
            if (left->balance() >= 1) // LL
            {
                this->rotateLeft();
                recalculateHeights();
            }
            else if (left->balance() <= -1) // LR
            {
                left->rotateLeft();
                this->rotateRight();
                recalculateHeights();
            }
        }
    }

    void _printTree(int indent) 
    {
        if (right) 
        {
            right->_printTree(indent + 1);
        }

        printIndent(indent);
        cout << value << endl;

        if (left) 
        {
            left->_printTree(indent + 1);
        }
    }

    void printIndent(int indent) 
    {
        for (size_t i = 0; i < indent; i++) 
        {
            cout << "   ";
        }
    }
};

class AVL
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

        curr->recalculateHeights();
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
            if (!curr->left && !curr->right)
            {
                // no children nodes
                free(curr);
                return nullptr;
            }
            else if (!curr->left)
            {
                // only a right child node
                Node* tmp = curr->right;
                free(curr);
                return tmp;
            } 
            else if (!curr->right)
            {
                // only a left child node
                Node* tmp = curr->left;
                free(curr);
                return tmp;
            }
            else
            {
                // has both children nodes
                Node* swapWith = curr->right;
                while (swapWith->left)
                {
                    swapWith = swapWith->left;
                }

                curr->value = swapWith->value;
                curr->right = _remove(swapWith->value, curr->right);
            }
        }
        curr->recalculateHeights();
        curr->fixTree();

        return curr;
    }
public:
    AVL()
    {
        this->root = nullptr;
    }

    void insert(int v)
    {
        root = _insert(v, root);
    }

    void remove(int v)
    {
        root = _remove(v, root);
    }

    void printTree() {
        if (root) {
            root->_printTree(0);
        }
    }
};

int main()
{
    AVL s;

    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(4);
    s.insert(5);

    s.printTree();

    return 0;
}