/*You are given an m x n matrix board containing letters 'X' and 'O', capture regions that are surrounded:

    Connect: A cell is connected to adjacent cells horizontally or vertically.
    Region: To form a region connect every 'O' cell.
    Surround: The region is surrounded with 'X' cells if you can connect the region with 'X' cells and none of the region cells are on the edge of the board.

To capture a surrounded region, replace all 'O's with 'X's in-place within the original board. You do not need to return anything.



Example 1:

Input: board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]

Output: [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]

Explanation:

In the above diagram, the bottom region is not captured because it is on the edge of the board and cannot be surrounded.

Example 2:

Input: board = [["X"]]

Output: [["X"]]
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    void solve(vector<vector<char>> &board)
    {
        int n = board.size();
        int m = board[0].size();

        vector<vector<bool>> visited(n, vector<bool>(m, false));

        for (int i = 0; i < n; i++)
        {
            dfs(board, visited, i, 0);
            dfs(board, visited, i, m - 1);
        }
        for (int i = 1; i < m - 1; i++)
        {
            dfs(board, visited, 0, i);
            dfs(board, visited, n - 1, i);
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                board[i][j] = board[i][j] == 'T' ? 'O' : 'X';
            }
        }
    }

private:
    void dfs(vector<vector<char>> &board, vector<vector<bool>> &visited, int r, int c)
    {
        int n = board.size();
        int m = board[0].size();

        if (r < 0 || c < 0 || r >= n || c >= m)
        {
            return;
        }
        if (visited[r][c] || board[r][c] == 'X')
        {
            return;
        }

        visited[r][c] = true;

        if (board[r][c] == 'O')
        {
            board[r][c] = 'T';
        }

        dfs(board, visited, r + 1, c);
        dfs(board, visited, r - 1, c);
        dfs(board, visited, r, c + 1);
        dfs(board, visited, r, c - 1);
    }
};