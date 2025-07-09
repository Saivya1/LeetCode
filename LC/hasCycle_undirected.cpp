/*Given an undirected graph with V vertices labeled from 0 to V-1. The graph is represented using an adjacency list where adj[i] lists all nodes connected to node. Determine if the graph contains any cycles.

Note: The graph does not contain any self-edges (edges where a vertex is connected to itself).
Examples:


Input: V = 6, adj= [[1, 3], [0, 2, 4], [1, 5], [0, 4], [1, 3, 5], [2, 4]]

Output: True

Explanation: The graph contains a cycle: 0 ->1 -> 2 -> 5 -> 4 -> 1.

Input: V = 4, adj= [[1, 2], [0], [0, 3], [2]]

Output: False

Explanation: The graph does not contain any cycles.*/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    bool isCycle(int V, vector<vector<int>> &adj)
    {
        vector<bool> visited(V, false);

        for (int i = 0; i < V; ++i)
        {
            if (!visited[i])
            {
                if (hasCycle(i, -1, adj, visited))
                    return true;
            }
        }

        return false;
    }

private:
    bool hasCycle(int node, int parent, vector<vector<int>> &adj, vector<bool> &visited)
    {
        visited[node] = true;

        for (int neighbour : adj[node])
        {
            if (!visited[neighbour])
            {
                if (hasCycle(neighbour, node, adj, visited))
                    return true;
            }
            else if (neighbour != parent)
            {
                return true;
            }
        }

        return false;
    }
};
