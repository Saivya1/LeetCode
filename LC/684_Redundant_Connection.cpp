/*In this problem, a tree is an undirected graph that is connected and has no cycles.

You are given a graph that started as a tree with n nodes labeled from 1 to n, with one additional edge added. The added edge has two different vertices chosen from 1 to n, and was not an edge that already existed. The graph is represented as an array edges of length n where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the graph.

Return an edge that can be removed so that the resulting graph is a tree of n nodes. If there are multiple answers, return the answer that occurs last in the input.



Example 1:

Input: edges = [[1,2],[1,3],[2,3]]
Output: [2,3]

Example 2:

Input: edges = [[1,2],[2,3],[3,4],[1,4],[1,5]]
Output: [1,4]
*/

#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> parent, depth;

    int find(int x)
    {
        if (parent[x] != x)
            parent[x] = find(parent[x]); // Path compression
        return parent[x];
    }

    bool merge(int x, int y)
    {
        int rootX = find(x), rootY = find(y);
        if (rootX == rootY)
            return false; // Cycle found
        if (depth[rootX] > depth[rootY])
            swap(rootX, rootY);
        parent[rootX] = rootY;
        if (depth[rootX] == depth[rootY])
            depth[rootY]++;
        return true;
    }

    vector<int> findRedundantConnection(vector<vector<int>> &edges)
    {
        int n = edges.size();
        parent.resize(n + 1);
        depth.assign(n + 1, 1);
        iota(parent.begin(), parent.end(), 0); // Initialize parent[i] = i

        for (auto &edge : edges)
        {
            if (!merge(edge[0], edge[1]))
                return edge; // This edge creates a cycle
        }
        return {};
    }
};
