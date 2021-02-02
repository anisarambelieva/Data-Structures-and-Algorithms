#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// the graph is undirected weighted

/*
struct Pair
{
    int valueNeigh;
    int weightPath;

    Pair(int v, int w) : valueNeigh(v), weightPath(w) { }
}; */


struct Node
{
    vector<int> neighbours;

    void addNeighbour(int v)
    {
        this->neighbours.push_back(v);
    }

    bool hasNeigh(int v)
    {
        for (auto curr : neighbours)
        {
            if (curr == v)
            {
                return true;
            }
        }
        return false;
    }
};

class Graph
{
    vector<Node> adjlist;
    vector<bool> visited;

    void _bfs(vector<bool>& visited, int x)
    {
        vector<bool> visitedHelper;
        visitedHelper.resize(visited.size(), false);

        queue<int> que;
        que.push(x);
        visitedHelper[x] = true;
        visited[x] = true;

        while (!que.empty())
        {
            int curr = que.front();
            que.pop();

            for (auto neigh : adjlist[curr].neighbours)
            {
                if (visitedHelper[neigh] == false)
                {
                    que.push(neigh);
                    visitedHelper[neigh] = true;
                    visited[neigh] = true;
                }
            }
        }
    }

public:
    Graph(int count)    
    {
        adjlist.resize(count);
        visited.resize(count, false);
    }

    void addNode(int from, int to)
    {
        adjlist[from].addNeighbour(to);
        adjlist[to].addNeighbour(from);
    }

    int countSubgraphs()
    {
        // start from the first unvisited 
        // do a bfs
        // counter++ when bfs is done
        // go until there are no more unvisited

        int count = 0;
        int currIndex = 0;

        for (auto curr : visited)
        {
            if (curr == false) // at first all are false
            {
                // do a bfs here
                _bfs(visited, currIndex);
                count++;
            }
            currIndex++;
        }
        return count;
    }
};

int main()
{
    int countTests;
    cin >> countTests;

    for (int i = 0; i < countTests; i++)
    {
        int countNodes, countEdges;
        cin >> countNodes >> countEdges;

        Graph g(countNodes);

        for (int j = 0; j < countEdges; j++)
        {
            int from, to;
            cin >> from >> to;
            g.addNode(from, to);
        }
        
        int result = g.countSubgraphs();
        cout << result << " ";
    }
}
