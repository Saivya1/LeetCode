from collections import deque


class Solution:
    def snakesAndLadders(self, board: List[List[int]]) -> int:
        r = len(board)
        c = len(board[0])

        queue = deque([(1, 0)])
        visited = set([1])

        def getCoord(pos):
            pos -= 1

            i = pos // c
            j = pos % c

            if i % 2 == 1:
                j = c - 1 - j

            i = r - 1 - i

            return [i, j]

        while queue:
            pos, moves = queue.popleft()

            if pos == r**2:
                return moves

            for d in range(1, 7):
                new_pos = pos + d

                if new_pos > r**2:
                    continue

                i, j = getCoord(new_pos)

                if board[i][j] != -1:
                    new_pos = board[i][j]

                if new_pos in visited:
                    continue

                visited.add(new_pos)
                queue.append((new_pos, moves + 1))

        return -1
