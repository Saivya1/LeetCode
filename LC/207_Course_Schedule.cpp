/* There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.



Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take.
To take course 1 you should have finished course 0. So it is possible.
Example 2:

Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take.
To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible. */

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> adj(numCourses);
        for (auto &pre : prerequisites)
        {
            adj[pre[0]].push_back(pre[1]);
        }

        vector<bool> visited(numCourses, false);
        vector<bool> onPath(numCourses, false); // recursion stack

        for (int i = 0; i < numCourses; i++)
        {
            if (!visited[i])
            {
                if (hasCycle(i, adj, visited, onPath))
                    return false; // cycle detected
            }
        }
        return true;
    }

private:
    bool hasCycle(int node, vector<vector<int>> &adj, vector<bool> &visited, vector<bool> &onPath)
    {
        visited[node] = true;
        onPath[node] = true;

        for (int neighbor : adj[node])
        {
            if (!visited[neighbor])
            {
                if (hasCycle(neighbor, adj, visited, onPath))
                    return true;
            }
            else if (onPath[neighbor])
            {
                return true; // cycle found
            }
        }

        onPath[node] = false; // backtrack
        return false;
    }
};
