#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution
{
public:
    int m, n;
    void wallsAndGates(vector<vector<int>> &rooms)
    {
        m = rooms.size();
        n = rooms[0].size();

        queue<pair<int, int>> q;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (rooms[i][j] == 0)
                {
                    q.push({i, j});
                }
            }
        }

        vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        while (!q.empty())
        {
            auto [x, y] = q.front();
            q.pop();

            for (auto [dx, dy] : dir)
            {
                int nx = x + dx;
                int ny = y + dy;

                if (nx < 0 || ny < 0 || nx >= m || ny >= n || rooms[nx][ny] != INT_MAX)
                {
                    continue;
                }

                rooms[nx][ny] = rooms[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
};