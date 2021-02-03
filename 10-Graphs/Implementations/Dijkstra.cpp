#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;

struct Pair
{
	int index;
	int distance;

	bool operator<(const Pair& rhs) const
	{
		return distance > rhs.distance;
	}
};

struct Edge
{
	int from;
	int to;
	int weight;
};

struct Node
{
	list<Pair> neighbours;

	bool hasNeighbour(int x)
	{
		for (auto n : neighbours)
		{
			if (n.index == x)
			{
				return true;
			}
		}
		return false;
	}

	void addNeighbour(int x, int d)
	{
		neighbours.push_back(Pair { x, d });
	}
};

class Graph
{
	vector<Node> adjList;

public:
	Graph(int count = 0)
	{
		adjList.resize(count);
	}

	void connect(int from, int to, int d)
	{
		if (!adjList[from].hasNeighbour(to))
		{
			adjList[from].addNeighbour(to, d);
		}
	}

	list<Edge> dijkstra(int start) const
	{
		if (adjList.size() < 1)
		{
			return list<Edge>();
		}

		vector<int> parent(adjList.size(), -1);
		vector<int> distance(adjList.size(), INT_MAX);
		vector<int> visited(adjList.size(), false);

		distance[start] = 0;

		priority_queue<Pair> nextToProcess;

		nextToProcess.push({ start, 0 });

		while (!nextToProcess.empty())
		{
			Pair curr = nextToProcess.top();
			nextToProcess.pop();

			int currNode = curr.index;

			if (visited[currNode])
			{
				continue;
			}

			visited[currNode] = true;

			for (auto n : adjList[currNode].neighbours)
			{
				int neighbourNode = n.index;
				int altDist = distance[currNode] + n.distance;

				if (altDist < distance[neighbourNode])
				{
					distance[neighbourNode] = altDist;
					parent[neighbourNode] = currNode;
					nextToProcess.push({ neighbourNode, altDist });
				}
			}
		}

		list<Edge> tree;
		for (int i = 0; i < parent.size(); i++)
		{
			if (parent[i] != -1)
			{
				int directDist = distance[i] - distance[parent[i]];
				tree.push_back({ parent[i], i, directDist });
			}
		}
		return tree;
	}
};

int main()
{
	Graph g(3);
	g.connect(0, 1, 5);
	g.connect(1, 2, 2);
	g.connect(2, 1, 21);
	g.connect(2, 0, 10);

	list<Edge> tree = g.dijkstra(0);
	cout << "Dijkstra tree:\n";
	for (Edge edge : tree) {
		cout << edge.from << "-" << edge.to << "(" << edge.weight << ")\n";
	}
}
