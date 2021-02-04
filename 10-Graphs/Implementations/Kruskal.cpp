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
        if (!nodes[from].hasNeighbour(to))
        {
            nodes[from].addNeighbour(to, weight);
            nodes[to].addNeighbour(from, weight);
        }
    }

    vector<Edge> getAllEdges() const
    {
        vector<Edge> tree;

        for (int from = 0; from < nodes.size(); from++)
        {
            for (auto n : nodes[from].neighbours)
            {
                int to = n.index;
                int weight = n.weight;

                if (from < to)
                {
                    tree.push_back({ from, to, weight });
                }
            }
        }

        return tree;
    }

    list<Edge> kruskal() const
    {
        if (nodes.size() < 1)
        {
            return list<Edge>();
        }

        vector<Edge> allEdges = getAllEdges();
        sort(allEdges.begin(), allEdges.end());

        list<Edge> tree;
        vector<int> components;
        components.resize(nodes.size());

        for (int i = 0; i < nodes.size(); i++)
        {
            components[i] = i;
        }

        for (auto e : allEdges)
        {
            if (components[e.from] != components[e.to])
            {
                tree.push_back(e);
                int oldComponent = components[e.from];
                int newComponent = components[e.to];

                for (int i = 0; i < components.size(); i++)
                {
                    if (components[i] == oldComponent)
                    {
                        components[i] = newComponent;
                    }
                }
            }
        }
        return tree;
    }
};

int main()
{
    Graph g(4);
    g.connect(0, 1, 5);
    g.connect(1, 2, 2);
    g.connect(1, 3, 8);
    g.connect(2, 0, 4);
    g.connect(2, 3, 3);
    g.connect(3, 0, 10);

    list<Edge> spanningTree = g.kruskal();
    for (Edge edge : spanningTree) {
        cout << edge.from << "-" << edge.to << "(" << edge.weight << ")\n";
    }
}
