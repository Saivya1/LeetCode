#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int n, m;
    int numIslands(vector<vector<char>> &grid)
    {
        n = grid.size();
        m = grid[0].size();
        int num = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == '1')
                {
                    num++;
                    dfs(i, j, grid);
                }
            }
        }

        return num;
    }

private:
    bool valid(int i, int j)
    {
        return i >= 0 && j >= 0 && i < n && j < m;
    }

    void dfs(int i, int j, vector<vector<char>> &grid)
    {
        if (!valid(i, j))
        {
            return;
        }
        if (grid[i][j] == '1')
        {
            grid[i][j] = 2;
            dfs(i + 1, j, grid);
            dfs(i, j + 1, grid);
            dfs(i - 1, j, grid);
            dfs(i, j - 1, grid);
        }
    }
};