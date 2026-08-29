from collections import deque


class Solution:
    def openLock(self, deadends: List[str], target: str) -> int:
        deadendSet = set(deadends)

        start = "0000"
        visited = set()

        if start in deadendSet:
            return -1

        queue = deque([(start, 0)])
        visited.add(start)

        while queue:
            curr_code, ctr = queue.popleft()

            if curr_code == target:
                return ctr

            for i in range(4):
                digit = int(curr_code[i])

                for change in [-1, +1]:
                    new_digit = (digit + change) % 10
                    new_code = curr_code[:i] + str(new_digit) + curr_code[i + 1 :]

                    if new_code in deadendSet:
                        continue
                    if new_code in visited:
                        continue

                    visited.add(new_code)
                    queue.append((new_code, ctr + 1))

        return -1
