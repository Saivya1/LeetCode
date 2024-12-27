#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <iostream>

using namespace std;

class Graph
{
    unordered_map<int, unordered_set<int>> adjList;
    int n;
    vector<bool> visited;
    int ctr;

public:
    Graph(int nodes, unordered_map<int, unordered_set<int>> edges)
    {
        n = nodes;
        adjList = edges;
        visited.resize(n, false);
        ctr = 0;
    }

    int CountConnected()
    {
        for (auto &it : adjList)
        {
            if (!visited[it.first])
            {
                dfsUtil(it.first);
                ctr++;
            }
        }

        // Handle isolated nodes
        for (int i = 0; i < n; ++i)
        {
            if (!visited[i])
            {
                ctr++;
            }
        }

        return ctr;
    }

private:
    void dfsUtil(int src)
    {
        visited[src] = true;

        for (int neighbour : adjList[src])
        {
            if (!visited[neighbour])
            {
                dfsUtil(neighbour);
            }
        }
    }
};

// Example usage
int main()
{
    unordered_map<int, unordered_set<int>> edges = {
        {0, {1, 2}},
        {1, {0, 3}},
        {2, {0}},
        {3, {1}},
        {4, {5}},
        {5, {4}},

    };

    Graph graph(8, edges);
    cout << graph.CountConnected();
}