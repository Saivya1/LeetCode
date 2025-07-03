#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> adj(numCourses);
        for (auto &vec : prerequisites)
        {
            adj[vec[1]].push_back(vec[0]);
        }

        vector<bool> visited(numCourses, false);
        vector<bool> recStack(numCourses, false);

        for (int i = 0; i < numCourses; i++)
        {
            if (!visited[i])
            {
                if (isCyclic(i, visited, recStack, adj))
                    return false;
            }
        }

        return true;
    }

    bool isCyclic(int node, vector<bool> &visited, vector<bool> &recStack, vector<vector<int>> &adj)
    {
        visited[node] = true;
        recStack[node] = true;

        for (int neigh : adj[node])
        {
            if (!visited[neigh] && isCyclic(neigh, visited, recStack, adj))
                return true;
            else if (recStack[neigh])
                return true;
        }

        recStack[node] = false;
        return false;
    }
};
