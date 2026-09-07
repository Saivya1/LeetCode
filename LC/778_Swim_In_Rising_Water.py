import heapq


class Solution:
    def swimInWater(self, grid: List[List[int]]) -> int:
        n = len(grid)
        heap = [(grid[0][0], 0, 0)]
        visited = set()

        while heap:
            t, i, j = heapq.heappop(heap)

            if (i, j) in visited:
                continue

            if i == n - 1 and j == n - 1:
                return t

            visited.add((i, j))

            for delI, delJ in [[1, 0], [0, 1], [-1, 0], [0, -1]]:
                newI = delI + i
                newJ = delJ + j

                if newI < 0 or newI >= n or newJ < 0 or newJ >= n:
                    continue

                if (newI, newJ) in visited:
                    continue

                newT = max(grid[newI][newJ], t)
                heapq.heappush(heap, (newT, newI, newJ))

        return -1
