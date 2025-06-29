#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int n, m;
    int numIslands(vector<vector<char>> &grid)
    {
        m = grid.size();
        n = grid[0].size();
        int ctr = 0;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == '1')
                {
                    ctr++;
                    dfs(grid, i, j);
                }
            }
        }

        return ctr;
    }
    void dfs(vector<vector<char>> &grid, int i, int j)
    {
        // First check bounds
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != '1')
            return;

        grid[i][j] = '2'; // mark as visited

        dfs(grid, i + 1, j);
        dfs(grid, i - 1, j);
        dfs(grid, i, j + 1);
        dfs(grid, i, j - 1);
    }
};