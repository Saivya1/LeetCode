from collections import deque


class Solution:
    def orangesRotting(self, grid: list[list[int]]) -> int:
        q = deque()
        rows = len(grid)
        cols = len(grid[0])
        fresh = 0
        minutes = -1

        for i in range(rows):
            for j in range(cols):
                if grid[i][j] == 1:
                    fresh += 1
                elif grid[i][j] == 2:
                    q.append((i, j))

        if fresh == 0:
            return 0
        if len(q) == 0:
            return -1
        dir = [(1, 0), (0, 1), (-1, 0), (0, -1)]

        while len(q) != 0:
            sz = len(q)
            while sz > 0:
                sz -= 1
                dxy = q[0]
                q.popleft()
                for delta in dir:
                    dx = dxy[0] + delta[0]
                    dy = dxy[1] + delta[1]

                    if dx < 0 or dy < 0 or dx >= rows or dy >= cols:
                        continue
                    if grid[dx][dy] != 1:
                        continue

                    grid[dx][dy] = 2
                    fresh -= 1
                    q.append((dx, dy))
            minutes += 1

        return minutes if fresh == 0 else -1
