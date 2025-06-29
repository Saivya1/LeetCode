#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int m, n;
    int ctr = 0;
    int maxi = 0;

    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        m = grid.size();
        n = grid[0].size();

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    ctr = 0;
                    dfs(grid, i, j);
                    maxi = max(ctr, maxi);
                }
            }
        }

        return maxi;
    }

    void dfs(vector<vector<int>> &grid, int i, int j)
    {
        if (i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == 0 || grid[i][j] == 2)
        {
            return;
        }
        ctr++;

        grid[i][j] = 2;

        dfs(grid, i + 1, j);
        dfs(grid, i, j + 1);
        dfs(grid, i - 1, j);
        dfs(grid, i, j - 1);
    }
};