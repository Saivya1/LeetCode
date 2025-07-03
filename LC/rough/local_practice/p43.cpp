#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int ctr = 0;

    int countComponents(int n, vector<vector<int>> &edges)
    {
        vector<vector<int>> adj(n);
        vector<bool> visited(n, false);

        for (auto &vec : edges)
        {
            adj[vec[0]].push_back(vec[1]);
            adj[vec[1]].push_back(vec[0]);
        }

        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                ctr++;
                dfs(i, adj, visited);
            }
        }

        return ctr;
    }

    void dfs(int node, vector<vector<int>> &adj, vector<bool> &visited)
    {
        visited[node] = true;

        for (int neigh : adj[node])
        {
            if (!visited[neigh])
            {
                dfs(neigh, adj, visited);
            }
        }
    }
};
