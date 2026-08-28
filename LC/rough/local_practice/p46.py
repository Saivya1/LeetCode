class Solution:
    def solve(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        r = len(board)
        c = len(board[0])

        edges = []

        for j in range(c):
            edges.append((0, j))
            edges.append((r - 1, j))
        for i in range(r):
            edges.append((i, 0))
            edges.append((i, c - 1))

        def dfs(i, j):
            board[i][j] = "S"
            dir = [[1, 0], [0, 1], [-1, 0], [0, -1]]

            for dxy in dir:
                nx = dxy[0] + i
                ny = dxy[1] + j

                if nx < 0 or nx >= r or ny < 0 or ny >= c:
                    continue

                if board[nx][ny] == "O":
                    board[nx][ny] = "S"
                    dfs(nx, ny)

        for i in range(r):
            for j in range(c):
                if (i, j) in edges and board[i][j] == "O":
                    dfs(i, j)
        for i in range(r):
            for j in range(c):
                if board[i][j] != "S":
                    board[i][j] = "X"
        for i in range(r):
            for j in range(c):
                if board[i][j] == "S":
                    board[i][j] = "O"
