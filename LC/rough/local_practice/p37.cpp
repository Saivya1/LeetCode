#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
    int m, n;
    int fresh = 0;
    int ctr = -1;
    int orangesRotting(vector<vector<int>> &grid)
    {
        m = grid.size();
        n = grid[0].size();

        queue<pair<int, int>> q;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 2)
                {
                    q.push({i, j});
                }
                if (grid[i][j] == 1)
                {
                    fresh++;
                }
            }
        }

        if (fresh == 0)
            return 0;
        if (q.empty())
            return -1;

        vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

        while (!q.empty())
        {
            int sz = q.size();

            while (sz--)
            {
                auto [x, y] = q.front();
                q.pop();

                for (auto [dx, dy] : dir)
                {
                    int nx = x + dx;
                    int ny = y + dy;

                    if (nx < 0 || ny < 0 || nx >= m || ny >= n)
                        continue;
                    if (grid[nx][ny] != 1)
                        continue;

                    grid[nx][ny] = 2;
                    fresh--;

                    q.push({nx, ny});
                }
            }

            ctr++;
        }

        return fresh == 0 ? ctr : -1;
    }
};