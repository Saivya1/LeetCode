/* Number of Connected Components in an Undirected Graph

There is an undirected graph with n nodes. There is also an edges array, where edges[i] = [a, b] means that there is an edge between node a and node b in the graph.

The nodes are numbered from 0 to n - 1.

Return the total number of connected components in that graph.

Example 1:

Input:
n=3
edges=[[0,1], [0,2]]

Output:
1

Example 2:

Input:
n=6
edges=[[0,1], [1,2], [2,3], [4,5]]

Output:
2
*/

#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    int countComponents(int n, vector<vector<int>> &edges)
    {
        vector<vector<int>> adj(n);
        vector<bool> visit(n, false);
        for (const auto &edge : edges)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        int res = 0;
        for (int node = 0; node < n; ++node)
        {
            if (!visit[node])
            {
                dfs(adj, visit, node);
                res++;
            }
        }
        return res;
    }

private:
    void dfs(const vector<vector<int>> &adj, vector<bool> &visit, int node)
    {
        visit[node] = true;
        for (int nei : adj[node])
        {
            if (!visit[nei])
            {
                dfs(adj, visit, nei);
            }
        }
    }
};