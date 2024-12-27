/* Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

You must do it in place.



Example 1:


Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]
Example 2:


Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]] */

#include <iostream>
#include <vector>

using namespace std;

class Solution
{

public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        vector<pair<int, int>> indices;
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[0].size(); j++)
            {
                if (matrix[i][j] == 0)
                {
                    indices.push_back({i, j});
                }
            }
        }
        for (auto p : indices)
        {
            util(p.first, p.second, matrix);
        }
    }

private:
    void util(int i, int j, vector<vector<int>> &matrix)
    {
        for (int k = 0; k < matrix[0].size(); k++)
        {
            matrix[i][k] = 0;
        }
        for (int l = 0; l < matrix.size(); l++)
        {
            matrix[l][j] = 0;
        }
    }
};

int main()
{
    vector<vector<int>> matrix{{0, 1, 2, 0},
                               {3, 4, 5, 2},
                               {1, 3, 1, 5}};

    vector<vector<int>> matrix2 = {{1, 1, 1},
                                   {1, 0, 1},
                                   {1, 1, 1}};

    Solution s;

    s.setZeroes(matrix);

    for (auto it : matrix)
    {
        for (int x : it)
        {
            cout << x << " ";
        }
        cout << endl;
    }
}