from collections import deque


class Solution:
    def shortestPathBinaryMatrix(self, grid: List[List[int]]) -> int:
        n = len(grid)
        if grid[0][0] != 0 or grid[n - 1][n - 1] != 0:
            return -1
        queue = deque([(0, 0, 1)])

        while queue:
            i, j, pathLen = queue.popleft()

            if i == n - 1 and j == n - 1:
                return pathLen

            for k in [
                [0, 1],
                [1, 0],
                [-1, 0],
                [0, -1],
                [1, 1],
                [1, -1],
                [-1, 1],
                [-1, -1],
            ]:
                next_i = i + k[0]
                next_j = j + k[1]

                if next_i < 0 or next_i >= n or next_j < 0 or next_j >= n:
                    continue
                if grid[next_i][next_j] != 0:
                    continue

                grid[next_i][next_j] = 1
                queue.append((next_i, next_j, pathLen + 1))

        return -1
