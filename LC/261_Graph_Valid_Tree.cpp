/*Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each edge is a pair of nodes), write a function to check whether these edges make up a valid tree.

Example 1:

Input:
n = 5
edges = [[0, 1], [0, 2], [0, 3], [1, 4]]

Output:
true

Example 2:

Input:
n = 5
edges = [[0, 1], [1, 2], [2, 3], [1, 3], [1, 4]]

Output:
false
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    bool validTree(int n, vector<vector<int>> &edges)
    {
        if (edges.size() != n - 1)
        {
            return false; // Must have exactly n - 1 edges
        }

        // Step 1: Build adjacency list for undirected graph
        vector<vector<int>> adj(n);
        for (const auto &edge : edges)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]); // undirected
        }

        // Step 2: DFS to check connectivity
        vector<bool> visited(n, false);
        if (hasCycle(0, -1, adj, visited))
        {
            return false; // Found a cycle
        }

        // Step 3: Check if all nodes were visited (i.e., graph is connected)
        for (bool v : visited)
        {
            if (!v)
                return false; // Disconnected node found
        }

        return true;
    }

private:
    // DFS to detect cycle in undirected graph
    bool hasCycle(int node, int parent, const vector<vector<int>> &adj, vector<bool> &visited)
    {
        visited[node] = true;

        for (int neighbor : adj[node])
        {
            if (!visited[neighbor])
            {
                if (hasCycle(neighbor, node, adj, visited))
                {
                    return true;
                }
            }
            else if (neighbor != parent)
            {
                // If the neighbor is visited and not the parent, we found a cycle
                return true;
            }
        }

        return false;
    }
};
