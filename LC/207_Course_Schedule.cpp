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

#include <vector>
using namespace std;

class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> adjList(numCourses);
        vector<bool> visited(numCourses, false);
        vector<bool> recStack(numCourses, false); // Recursion stack to detect cycles

        for (const auto &it : prerequisites)
        {
            adjList[it[0]].push_back(it[1]);
        }

        for (int i = 0; i < numCourses; ++i)
        {
            if (!visited[i])
            {
                if (dfsUtil(i, adjList, visited, recStack))
                {
                    return false; // Cycle detected
                }
            }
        }
        return true;
    }

private:
    bool dfsUtil(int node, const vector<vector<int>> &adjList, vector<bool> &visited, vector<bool> &recStack)
    {
        visited[node] = true;
        recStack[node] = true;

        for (int neighbor : adjList[node])
        {
            if (!visited[neighbor])
            {
                if (dfsUtil(neighbor, adjList, visited, recStack))
                {
                    return true; // Cycle detected
                }
            }
            else if (recStack[neighbor])
            {
                return true; // Cycle detected
            }
        }

        recStack[node] = false;
        return false;
    }
};

int main()
{
}