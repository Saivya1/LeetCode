/*You're given n courses labeled from 1 to n, and an array of relations where each pair [u, v] denotes u → v (must take u before v).

In each semester, you can take any number of courses as long as all their prerequisites have been met.

Return the minimum number of semesters needed to complete all courses, or -1 if it's impossible.

Example:

Input: n = 3, relations = [[1,3],[2,3]]
Output: 2
Explanation:
  - Semester 1: take courses 1 and 2 (no prerequisites)
  - Semester 2: take course 3*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int minimumSemesters(int n, vector<vector<int>> &relations)
{
    vector<vector<int>> adjlist(n + 1);
    vector<int> indeg(n + 1, 0);

    for (auto &vec : relations)
    {
        adjlist[vec[0]].push_back(vec[1]);
        indeg[vec[1]]++;
    }

    queue<int> q;

    for (int i = 1; i <= n; i++)
    {
        if (indeg[i] == 0)
        {
            q.push(i);
        }
    }

    int sem = 0, done = 0;

    while (!q.empty())
    {
        int size = q.size();
        sem++;
        while (size--)
        {
            int node = q.front();
            q.pop();
            done++;

            for (int v : adjlist[node])
            {
                if (--indeg[v] == 0)
                    q.push(v);
            }
        }
    }

    return done == n ? sem : -1;
}