#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> adj(numCourses);
        vector<int> indeg(numCourses);
        queue<int> q;
        int ctr = 0;

        for (auto &vec : prerequisites)
        {
            adj[vec[1]].push_back(vec[0]);
            indeg[vec[0]]++;
        }

        for (int i = 0; i < numCourses; i++)
        {
            if (indeg[i] == 0)
            {
                q.push(i);
            }
        }

        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            ctr++;

            for (int neigh : adj[node])
            {
                indeg[neigh]--;
                if (indeg[neigh] == 0)
                {
                    q.push(neigh);
                }
            }
        }

        return ctr == numCourses;
    }
};