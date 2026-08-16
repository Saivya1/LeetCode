/*Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.

The distance between two cells sharing a common edge is 1.



Example 1:

Input: mat = [[0,0,0],[0,1,0],[0,0,0]]
Output: [[0,0,0],[0,1,0],[0,0,0]]

Example 2:

Input: mat = [[0,0,0],[0,1,0],[1,1,1]]
Output: [[0,0,0],[0,1,0],[1,2,1]]
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int m, n;
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
    {
        m = mat.size();
        n = mat[0].size();
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (mat[i][j] == 0)
                {
                    dfs(i, j, mat);
                }
            }
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (mat[i][j] == INT_MAX)
                {
                    mat[i][j] = 0;
                }
            }
        }

        return mat;
    }

    void dfs(int i, int j, vector<vector<int>> &mat)
    {
        if (i >= m || j >= n || i < 0 || j < 0)
        {
            return;
        }

        if (mat[i][j] != 0)
        {
            mat[i][j]++;
        }
        mat[i][j] = INT_MAX;

        dfs(i + 1, j, mat);
        dfs(i, j + 1, mat);
        dfs(i - 1, j, mat);
        dfs(i, j - 1, mat);
    }
};
