#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
using namespace std;

struct Pair
{
    int index;
    int weight;
};

struct Node
{
    list<Pair> neighbours;

    bool hasNeighbour(int i)
    {
        for (auto n : neighbours)
        {
            if (n.index == i)
            {
                return true;
            }
        }
        return false;
    }

    void addNeighbour(int i, int w)
    {
        neighbours.push_back({ i, w });
    }
};

struct Edge
{
    int from;
    int to;
    int weight;

    bool operator<(Edge& rhs) const
    {
        return weight < rhs.weight;
    }
};

class Graph
{
    vector<Node> nodes;

public:
    Graph(int size = 0)
    {
        nodes.resize(size);
    }

    void connect(int from, int to, int weight)
    {
        // it is a multigraph
        nodes[from].addNeighbour(to, weight);
        nodes[to].addNeighbour(from, weight);
    }

    vector<Edge> getAllEdges() const
    {
        vector<Edge> result;

        for (long unsigned int i = 0; i < nodes.size(); i++)
        {
            for (auto n : nodes[i].neighbours)
            {
                int to = n.index;
                int weight = n.weight;

                if (i < to)
                {
                    result.push_back({ i, to, weight });
                }
            }
        }

        return result;
    }

    vector<Edge> kruskal() const
    {
        if (nodes.size() < 1)
        {
            return vector<Edge>();
        }

        vector<Edge> allEdges = getAllEdges();
        sort(allEdges.begin(), allEdges.end());

        vector<Edge> tree;
        vector<int> components;
        components.resize(nodes.size());

        for (long unsigned int i = 0; i < nodes.size(); i++)
        {
            components[i] = i;
        }

        for (auto edge : allEdges)
        {
            if (components[edge.from] != components[edge.to])
            {
                tree.push_back(edge);
                int oldC = components[edge.from];
                int newC = components[edge.to];

                for (int i = 0; i < components.size(); i++)
                {
                    if (components[i] == oldC)
                    {
                        components[i] = newC;
                    }
                }
            }
        }
        return tree;
    }
};

int main()
{
    int countV;
    int countE;

    cin >> countV >> countE;

    int from, to, weight;

    Graph g(countV);

    for (int i = 0; i < countE; i++)
    {
        cin >> from >> to >> weight;
        g.connect(from, to, weight);
    }

    vector<Edge> tree = g.kruskal();
    int res = 0;

    for (long unsigned int i = 0; i < tree.size(); i++)
    {
        res += tree[i].weight;
    }

    cout << res;
    return 0;
}
