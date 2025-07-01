#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int m, n, prev = 0;

    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
    {
        m = heights.size();
        n = heights[0].size();

        vector<vector<int>> res;
        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++)
        {
            dfs(heights, pacific, i, 0, heights[i][0]);
            dfs(heights, atlantic, i, n - 1, heights[i][n - 1]);
        }

        for (int j = 0; j < n; j++)
        {
            dfs(heights, pacific, 0, j, heights[0][j]);
            dfs(heights, atlantic, m - 1, j, heights[m - 1][j]);
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (atlantic[i][j] && pacific[i][j])
                {
                    res.push_back({i, j});
                }
            }
        }

        return res;
    }

    void dfs(vector<vector<int>> &heights, vector<vector<bool>> &visited, int r, int c, int prev)
    {
        if (r >= m || c >= n || r < 0 || c < 0 || heights[r][c] < prev)
        {
            return;
        }
        if (visited[r][c])
        {
            return;
        }

        visited[r][c] = true;
        dfs(heights, visited, r - 1, c, heights[r][c]);
        dfs(heights, visited, r + 1, c, heights[r][c]);
        dfs(heights, visited, r, c - 1, heights[r][c]);
        dfs(heights, visited, r, c + 1, heights[r][c]);
    }
};