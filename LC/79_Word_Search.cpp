/*Given an m x n grid of characters board and a string word, return true if word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.



Example 1:

Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
Output: true

Example 2:

Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
Output: true

Example 3:

Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
Output: false
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    bool exist(vector<vector<char>> &board, string word)
    {
        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (dfs(board, word, i, j, 0))
                {
                    return true;
                }
            }
        }

        return false;
    }

private:
    bool dfs(vector<vector<char>> &board, const string &word, int i, int j, int k)
    {
        int m = board.size(), n = board[0].size();

        if (k == word.length())
            return true;
        if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] != word[k])
            return false;

        char temp = board[i][j];
        board[i][j] = '\0';

        bool found = dfs(board, word, i + 1, j, k + 1) ||
                     dfs(board, word, i - 1, j, k + 1) ||
                     dfs(board, word, i, j + 1, k + 1) ||
                     dfs(board, word, i, j - 1, k + 1);

        board[i][j] = temp;
        return found;
    }
};
