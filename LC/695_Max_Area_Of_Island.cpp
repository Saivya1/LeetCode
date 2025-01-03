/* You are given an m x n binary matrix grid. An island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

The area of an island is the number of cells with a value 1 in the island.

Return the maximum area of an island in grid. If there is no island, return 0.



Example 1:


Input: grid = [[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,1,1,0,1,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],[0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]
Output: 6
Explanation: The answer is not 11, because the island must be connected 4-directionally.
Example 2:

Input: grid = [[0,0,0,0,0,0,0,0]]
Output: 0 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int m, n;
    int maxi;
    int ctr;

    bool inside(int i, int j)
    {
        return (i >= 0) && (i < m) && (j >= 0) && (j < m);
    }
    void dfs(int i, int j, vector<vector<int>> &grid)
    {

        ctr++;
        if (!inside(i, j))
            return;

        if (grid[i][j] == '1')
        {
            grid[i][j] = 2;
            dfs(i - 1, j, grid);
            dfs(i, j - 1, grid);
            dfs(i + 1, j, grid);
            dfs(i, j + 1, grid);
        }
        maxi = max(maxi, ctr);
    }

    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == '1')
                {
                    ctr = 0;
                    dfs(i, j, grid);
                }
            }
        }
        return maxi;
    }
};