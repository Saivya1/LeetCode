#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<int> res;
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> adj(numCourses);
        vector<bool> visited(numCourses, false);
        vector<bool> recstack(numCourses, false);

        for (auto &vec : prerequisites)
        {
            adj[vec[1]].push_back(vec[0]);
        }

        for (int i = 0; i < numCourses; i++)
        {
            if (!visited[i])
            {
                if (isCyclic(i, adj, visited, recstack))
                {
                    return {};
                }
            }
        }

        reverse(res.begin(), res.end());
        return res;
    }

    bool isCyclic(int node, vector<vector<int>> &adj, vector<bool> &visited, vector<bool> &recstack)
    {
        visited[node] = true;
        recstack[node] = true;

        for (int neigh : adj[node])
        {
            if (!visited[neigh] && isCyclic(neigh, adj, visited, recstack))
            {
                return true;
            }
            else if (recstack[neigh])
            {
                return true;
            }
        }

        res.push_back(node);
        recstack[node] = false;
        return false;
    }
};