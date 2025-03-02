/* There is an undirected star graph consisting of n nodes labeled from 1 to n. A star graph is a graph where there is one center node and exactly n - 1 edges that connect the center node with every other node.

You are given a 2D integer array edges where each edges[i] = [ui, vi] indicates that there is an edge between the nodes ui and vi. Return the center of the given star graph.



Example 1:


Input: edges = [[1,2],[2,3],[4,2]]
Output: 2
Explanation: As shown in the figure above, node 2 is connected to every other node, so 2 is the center.
Example 2:

Input: edges = [[1,2],[5,1],[1,3],[1,4]]
Output: 1 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <bitset>

using namespace std;

// class Solution
// {
// public:
//     int findCenter(vector<vector<int>> &edges)
//     {
//         unordered_map<int, int> um;
//         int n = edges.size();

//         for (vector<int> vec : edges)
//         {
//             for (int x : vec)
//             {
//                 um[x]++;
//             }
//         }
//         for (auto it : um)
//         {
//             if (it.second == n)
//             {
//                 return it.first;
//             }
//         }
//         return -1;
//     }

// };

// Better Solution

class Solution
{
public:
    int findCenter(vector<vector<int>> &edges)
    {
        bitset<100000> visited = 0;
        for (auto &e : edges)
        {
            int v = e[0], w = e[1];
            if (visited[v])
                return v;
            if (visited[w])
                return w;
            visited[v] = visited[w] = 1;
        }
        return -1;
    }
};

int main()
{
    vector<vector<int>> edges{{1, 2}, {2, 3}, {4, 2}};

    Solution s;

    cout << s.findCenter(edges);
}