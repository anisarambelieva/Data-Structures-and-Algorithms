#include <iostream>
#include <vector>
using namespace std;

void swap(int& a, int& b) 
{
    int temp = a;
    a = b;
    b = temp;
}

class Heap
{
private:
    vector<int> data;

    int getLeftChildPosition(int pos)
    {
        return (pos * 2) + 1;
        /* 1 2 3 4 5 6 7 8
           if the pos is 2 (element = 3) 
           its left child is on position 2*2+1 = 5
           which is element 6 */

        /*       1
               /   \
              2     3
             / \   / \
            4  5  6   7
        */
    }

    int getRightChildPosition(int pos)
    {
        return (pos * 2) + 2;
    }

    int getParentPosition(int pos)
    {
        return (pos - 1) / 2;
    }

    void siftUp(int pos)
    {
        int parent = getParentPosition(pos);

        while (data[pos] > data[parent])
        {
            swap(data[pos], data[parent]);
            if (parent <= 0)
            {
                return;
            }
            // move up to check the rest
            pos = getParentPosition(pos);
            parent = getParentPosition(parent);
        }
    }

    void siftDown(int pos)
    {
        bool hasRightChild = getRightChildPosition(pos) < this->data.size();
        bool hasLeftChild = getRightChildPosition(pos) < this->data.size();

        // if the element a right child it for sure has a left one
        // because we have a complete binary tree
        if (hasRightChild 
            && (data[pos] < data[getLeftChildPosition(pos)] 
                || data[pos] < data[getRightChildPosition(pos)]))
        {
            int swapWith = -1;
            if (data[getLeftChildPosition(pos)] > data[getRightChildPosition(pos)])
            {
                swapWith = getLeftChildPosition(pos);
            } 
            else
            {
                swapWith = getRightChildPosition(pos);
            }

            swap(data[pos], data[swapWith]);
            siftDown(swapWith);
        }
        else if (hasLeftChild && data[pos] < data[getLeftChildPosition(pos)])
        {
            swap(data[pos], data[getLeftChildPosition(pos)]);
            siftDown(getLeftChildPosition(pos));
        }
    }

public:
    bool isEmpty() const
    {
        return this->data.size() == 0;
    }

    void add(int number)
    {
        this->data.push_back(number);
        this->siftUp(this->data.size() - 1);
    }

    int peekTop() const
    {
        return this->data[0];
    }

    void popTop()
    {
        if (this->isEmpty())
        {
            return;
        }

        swap(this->data[0], this->data[this->data.size() - 1]);
        this->data.pop_back();
        siftDown(0);
    }
};

int main()
{
    Heap s;
    s.add(1);
    s.add(5);
    s.add(3);
    s.add(4);
    s.add(2);

    while (!s.isEmpty()) 
    {
        cout << s.peekTop() << " ";
        s.popTop();
    }
    cout << "\n";
}
