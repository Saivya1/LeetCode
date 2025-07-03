#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    bool validTree(int n, vector<vector<int>> &edges)
    {
        vector<vector<int>> adj(n);
        vector<bool> visited(n, false);

        if (edges.size() != n - 1)
            return false;

        for (auto &vec : edges)
        {
            adj[vec[0]].push_back(vec[1]);
            adj[vec[1]].push_back(vec[0]);
        }

        isCyclic(0, -1, visited, adj);

        for (bool x : visited)
        {
            if (!x)
            {
                return false;
            }
        }

        return true;
    }

    bool isCyclic(int node, int parent, vector<bool> &visited, vector<vector<int>> &adj)
    {
        visited[node] = true;

        for (int neigh : adj[node])
        {
            if (!visited[neigh])
            {
                if (isCyclic(neigh, node, visited, adj))
                    return true;
            }
            else if (neigh != parent)
            {
                return true;
            }
        }

        return false;
    }
};
