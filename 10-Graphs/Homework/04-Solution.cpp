#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;

void printPath(vector<string> path)
{
    int size = path.size();
    for (auto c : path)
        cout << c << " ";
    cout << endl;
}

bool isVisited(string c, vector<string>& path)
{
    int size = path.size();
    for (auto curr : path)
        if (curr == c)
            return true;
    return false;
}

void findPath(unordered_map<string, unordered_set<string>>& cities, string src)
{
    queue<vector<string>> que;

    vector<string> path;
    path.push_back(src);
    que.push(path);

    while (!que.empty())
    {
        path = que.front();
        que.pop();

        string last = path[path.size() - 1];

        if (last == src && path.size() != 1)
        {
            printPath(path);
            return;
        }

        for (auto c : cities[last])
        {
            if (!isVisited(c, path) || c == src)
            {
                vector<string> newpath(path);
                newpath.push_back(c);
                que.push(newpath);
            }
        }
    }
}

int main()
{
    int countCitites, countTickets;
    cin >> countCitites >> countTickets;

    unordered_map<string, unordered_set<string>> cities;

    for (int i = 0; i < countTickets; i++)
    {
        string from, to;
        cin >> from >> to;
        cities[from].insert(to);
    }

    string target;
    cin >> target;

    findPath(cities, target);
}
