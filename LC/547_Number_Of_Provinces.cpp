/* There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.

A province is a group of directly or indirectly connected cities and no other cities outside of the group.

You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.

Return the total number of provinces.



Example 1:


Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
Output: 2
Example 2:


Input: isConnected = [[1,0,0],[0,1,0],[0,0,1]]
Output: 3  */

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
    vector<bool> visited;
    int ctr;

public:
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int n = isConnected.size();
        visited.resize(n, false);
        ctr = 0;

        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                ctr++;
                dfsUtil(i, isConnected);
            }
        }
        return ctr;
    }

private:
    void dfsUtil(int v, vector<vector<int>> &adjMat)
    {
        visited[v] = true;

        for (int i = 0; i < adjMat.size(); i++)
        {
            if (adjMat[v][i] == 1 && !visited[i])
            {
                dfsUtil(i, adjMat);
            }
        }
    }
};