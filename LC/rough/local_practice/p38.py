from collections import deque


class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        fresh = 0
        time = -1
        queue = deque()
        row = len(grid)
        col = len(grid[0])

        for i in range(row):
            for j in range(col):
                if grid[i][j] == 1:
                    fresh += 1
                if grid[i][j] == 2:
                    queue.append((i, j))
        if fresh == 0:
            return 0

        dxy = [[1, 0], [0, 1], [-1, 0], [0, -1]]

        while queue:
            sz = len(queue)
            time += 1
            while sz:
                sz -= 1
                xy = queue.popleft()
                for dir in dxy:
                    new_x = dir[0] + xy[0]
                    new_y = dir[1] + xy[1]
                    if new_x < 0 or new_y < 0 or new_x >= row or new_y >= col:
                        continue

                    if grid[new_x][new_y] == 1:
                        fresh -= 1
                        grid[new_x][new_y] = 2
                        queue.append((new_x, new_y))

        return time if fresh == 0 else -1
