#include <iostream>
#include <list>
#include <vector>
#include <queue>
using namespace std;

struct Node
{
    list<int> neighbours;

    void addNeighbour(int v)
    {
        this->neighbours.push_back(v);
    }

    bool hasNeighbour(int v)
    {
        for (auto n : neighbours)
        {
            if (n == v)
            {
                return true;
            }
        }
        return false;
    }
};

class Graph
{
private:
    vector<Node> adjList;

    void _BFS(int start, vector<bool>& visited)
    {
        queue<int> next;

        next.push(start);
        visited[start] = true;

        while (!next.empty())
        {
            int curr = next.front();
            next.pop();

            cout << curr << " ";

            for (auto n : adjList[curr].neighbours)
            {
                if (!visited[n])
                {
                    next.push(n);
                    visited[n] = true;
                }
            }
        }
    }

public:
    Graph(int size = 0)
    {
        adjList.resize(size);
    }

    void connect(int from, int to)
    {
        if (!adjList[from].hasNeighbour(to))
        {
            adjList[from].addNeighbour(to);
            adjList[to].addNeighbour(from);
        }
    }

    void BFS(int start)
    {
        vector<bool> visited;
        visited.resize(adjList.size(), false);

        _BFS(start, visited);
    }
};

int main()
{
    Graph g(4);
    g.connect(0, 1);
    g.connect(1, 0);
    g.connect(1, 2);
    g.connect(1, 3);
    g.connect(2, 1);
    g.connect(3, 1);
    g.connect(3, 2);

    g.BFS(3);
}
