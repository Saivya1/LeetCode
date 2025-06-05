/*Given an m x n matrix board where each cell is a battleship 'X' or empty '.', return the number of the battleships on board.

Battleships can only be placed horizontally or vertically on board. In other words, they can only be made of the shape 1 x k (1 row, k columns) or k x 1 (k rows, 1 column), where k can be of any size. At least one horizontal or vertical cell separates between two battleships (i.e., there are no adjacent battleships).



Example 1:

Input: board = [["X",".",".","X"],[".",".",".","X"],[".",".",".","X"]]
Output: 2

Example 2:

Input: board = [["."]]
Output: 0
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int m, n;
    int ctr;
    int countBattleships(vector<vector<char>> &board)
    {
        n = board.size();
        m = board[0].size();

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (board[i][j] == 'X')
                {
                    ctr++;
                    dfs(i, j, board);
                }
            }
        }

        return ctr;
    }

private:
    bool valid(int i, int j)
    {
        return i >= 0 && j >= 0 && i < n && j < m;
    }

    void dfs(int i, int j, vector<vector<char>> &board)
    {
        if (!valid(i, j))
        {
            return;
        }

        if (board[i][j] == 'X')
        {
            board[i][j] = 'Y';
            dfs(i + 1, j, board);
            dfs(i, j + 1, board);
            dfs(i - 1, j, board);
            dfs(i, j - 1, board);
        }
    }
};
