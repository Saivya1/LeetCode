#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    bool isCycle(int V, vector<vector<int>> &adj)
    {
        vector<bool> visited(V, false);
        vector<bool> recStack(V, false);

        for (int i = 0; i < V; ++i)
        {
            if (!visited[i])
            {
                if (hasCycle(i, adj, visited, recStack))
                    return true;
            }
        }

        return false;
    }

private:
    bool hasCycle(int node, vector<vector<int>> &adj, vector<bool> &visited, vector<bool> &recStack)
    {
        visited[node] = true;
        recStack[node] = true;

        for (int neighbour : adj[node])
        {
            if (!visited[neighbour])
            {
                if (hasCycle(neighbour, adj, visited, recStack))
                    return true;
            }
            else if (recStack[neighbour])
            {
                return true;
            }
        }

        recStack[node] = false; // backtrack
        return false;
    }
};
