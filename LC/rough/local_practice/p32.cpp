#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int n, m;
    int area = 0;
    int max_area = 0;
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        n = grid.size();
        m = grid[0].size();

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                {
                    area = 0;
                    dfs(i, j, grid);
                    max_area = max(area, max_area);
                }
            }
        }
        return max_area;
    }

private:
    bool valid(int i, int j)
    {
        return i >= 0 && j >= 0 && i < n && j < m;
    }

    void dfs(int i, int j, vector<vector<int>> &grid)
    {

        if (!valid(i, j))
        {
            return;
        }

        if (grid[i][j] == 1)
        {
            area++;
            grid[i][j] = 2;

            dfs(i + 1, j, grid);
            dfs(i, j + 1, grid);
            dfs(i - 1, j, grid);
            dfs(i, j - 1, grid);
        }
    }
};