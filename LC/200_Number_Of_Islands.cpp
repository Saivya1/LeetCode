/* Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.



Example 1:

Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1
Example 2:

Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3 */

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int n, m;
    bool inside(int i, int j)
    {
        return (0 <= i) && (i < n) && (0 <= j) && (j < m);
    }
    void dfs(int i, int j, vector<vector<char>> &grid)
    {
        if (!inside(i, j))
            return;
        if (grid[i][j] == '1')
        {
            grid[i][j] = '2';
            dfs(i + 1, j, grid);
            dfs(i, j + 1, grid);
            dfs(i - 1, j, grid);
            dfs(i, j - 1, grid);
        }
    }
    int numIslands(vector<vector<char>> &grid)
    {
        n = grid.size();
        m = grid[0].size();
        int num = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == '1')
                {
                    num++;
                    dfs(i, j, grid);
                }
            }
        return num;
    }
};