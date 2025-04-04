/* There is a bi-directional graph with n vertices, where each vertex is labeled from 0 to n - 1 (inclusive). The edges in the graph are represented as a 2D integer array edges, where each edges[i] = [ui, vi] denotes a bi-directional edge between vertex ui and vertex vi. Every vertex pair is connected by at most one edge, and no vertex has an edge to itself.

You want to determine if there is a valid path that exists from vertex source to vertex destination.

Given edges and the integers n, source, and destination, return true if there is a valid path from source to destination, or false otherwise.



Example 1:


Input: n = 3, edges = [[0,1],[1,2],[2,0]], source = 0, destination = 2
Output: true
Explanation: There are two paths from vertex 0 to vertex 2:
- 0 → 1 → 2
- 0 → 2
Example 2:


Input: n = 6, edges = [[0,1],[0,2],[3,5],[5,4],[4,3]], source = 0, destination = 5
Output: false
Explanation: There is no path from vertex 0 to vertex 5. */

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    bool validPath(int n, vector<vector<int>> &edges, int source, int destination)
    {
        vector<bool> visited(n, false);

        vector<vector<int>> adjList(n);

        for (vector<int> edge : edges)
        {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }
        return dfsUtil(source, visited, adjList, destination);
    }

private:
    bool dfsUtil(int v, vector<bool> &visited, vector<vector<int>> &adjList, int dst)
    {

        if (v == dst)
        {
            return true;
        }

        visited[v] = true;

        for (int neighbour : adjList[v])
        {
            if (!visited[neighbour])
            {
                if (dfsUtil(neighbour, visited, adjList, dst))
                {
                    return true;
                };
            }
        }
        return false;
    }
};