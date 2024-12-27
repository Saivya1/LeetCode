#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>

using namespace std;

class Graph
{
    unordered_map<int, unordered_set<int>> adjList;
    vector<bool> visited;

public:
    Graph(unordered_map<int, unordered_set<int>> um, int n)
    {
        adjList = um;
        visited.resize(n, false);
    }

    int dfsUtil(int src)
    {
        visited[src] = true;
        int count = 1; // Count the current node

        for (int neighbour : adjList[src])
        {
            if (!visited[neighbour])
            {
                count += dfsUtil(neighbour);
            }
        }

        return count;
    }

    int largestComp()
    {
        int maxi = 0;

        for (auto it : adjList)
        {
            if (!visited[it.first])
            {
                maxi = max(maxi, dfsUtil(it.first));
            }
        }

        return maxi;
    }
};

int main()
{
    unordered_map<int, unordered_set<int>> edges = {
        {0, {8, 1, 5}},
        {1, {0}},
        {5, {0, 8}},
        {8, {0, 5}},
        {2, {3, 4}},
        {3, {2, 4}},
        {4, {3, 2}},
    };

    Graph graph(edges, 7);
    cout << graph.largestComp();
}