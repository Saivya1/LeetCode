#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
    int m, n, time = 0, freshcount = 0;
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
                    freshcount++;
                }
            }
        }

        if (freshcount == 0)
            return 0;
        if (q.empty())
            return -1;

        vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

        while (!q.empty())
        {
            int size = q.size();
            time++;

            while (size--)
            {
                auto [x, y] = q.front();
                q.pop();

                for (auto [dx, dy] : dir)
                {
                    int nx = dx + x;
                    int ny = dy + y;

                    if (nx < 0 || ny < 0 || nx >= m || ny >= n || grid[nx][ny] != 1)
                    {
                        continue;
                    }

                    grid[nx][ny] = 2;
                    freshcount--;

                    q.push({nx, ny});
                }
            }
        }

        return freshcount == 0 ? time - 1 : -1;
    }
};