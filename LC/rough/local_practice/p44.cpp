#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int ctr = 0;
        int n = isConnected.size();
        vector<vector<int>> adj(n);

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (i != j && isConnected[i][j] == 1)
                {
                    adj[i].push_back(j);
                }
            }
        }

        vector<bool> visited(isConnected.size(), false);

        for (int i = 0; i < isConnected.size(); i++)
        {
            if (!visited[i])
            {
                ctr++;
                dfs(i, adj, visited);
            }
        }

        return ctr;
    }

    void dfs(int i, vector<vector<int>> &adj, vector<bool> &visited)
    {
        visited[i] = true;

        for (int neighbours : adj[i])
        {
            if (!visited[neighbours])
            {
                dfs(neighbours, adj, visited);
            }
        }
    }
};