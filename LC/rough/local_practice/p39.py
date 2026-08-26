class Solution:
    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        r = len(heights)
        c = len(heights[0])
        res = []

        pacific = set()
        atlantic = set()

        def dfs(i, j, ocean):
            if (i, j) in ocean:
                return

            ocean.add((i, j))

            dir = [[0, 1], [1, 0], [-1, 0], [0, -1]]

            for dxy in dir:
                nx = i + dxy[0]
                ny = j + dxy[1]

                if nx < 0 or nx >= r or ny < 0 or ny >= c:
                    continue

                if heights[nx][ny] >= heights[i][j]:
                    dfs(nx, ny, ocean)

        for j in range(c):
            dfs(0, j, pacific)
            dfs(r - 1, j, atlantic)

        for i in range(r):
            dfs(i, 0, pacific)
            dfs(i, c - 1, atlantic)

        for i in range(r):
            for j in range(c):
                if (i, j) in pacific and (i, j) in atlantic:
                    res.append([i, j])

        return res
