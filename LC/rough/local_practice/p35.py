class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        ctr = 0

        def dfs(i, j):
            if i < 0 or i >= len(grid) or j < 0 or j >= len(grid[0]):
                return
            if grid[i][j] == "1":
                grid[i][j] = "2"
                dfs(i + 1, j)
                dfs(i, j + 1)
                dfs(i, j - 1)
                dfs(i - 1, j)

        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == "1":
                    ctr += 1
                    dfs(i, j)
        return ctr
