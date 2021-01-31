#include <iostream>
#include <list>
#include <vector>
using namespace std;

struct Pair
{
    int value;
    int dist;

    Pair(int value, int dist) : value(value), dist(dist) { }
};

struct Node
{
    list<Pair> neighbours;

    void addNeighbour(int value, int dist)
    {
        neighbours.push_back({ value, dist });
    }

    int hasNeighbour(int value)
    {
        for (auto n : neighbours)
        {
            if (n.value == value)
            {
                return n.dist;
            }
        }
        return -1;
    }
};

class Graph
{
    vector<Node> adjlist;

public:
    Graph(int count = 0)
    {
        adjlist.resize(count);
    }

    void connect(int from, int to, int dist)
    {
        adjlist[from].addNeighbour(to, dist);
        adjlist[to].addNeighbour(from, dist);
    }

    int checkPath(int from, int to)
    {
        return adjlist[from].hasNeighbour(to);
    }
};

int main()
{
    /*
        4 5
        0 1 1
        0 2 2 
        2 3 5 
        2 1 3
        0 3 1
        3
        0 1 2
    */

    int countV, countE;
    cin >> countV >> countE;
    Graph g(countV);

    for (int i = 0; i < countE; i++)
    {
        int from, to, dist;
        cin >> from >> to >> dist;
        g.connect(from, to, dist);
    }

    int countVpath;
    cin >> countVpath;

    int from, to;
    cin >> from;

    int distance = 0;

    for (int i = 0; i < countVpath-1; i++)
    {
        cin >> to;
        int res = g.checkPath(from, to);

        if (res != -1)
        {
            distance += res;
        }
        else
        {
            distance = -1;
            break;
        }

        from = to;
    }

    cout << distance;
    return 0;
}