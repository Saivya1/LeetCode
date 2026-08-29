from collections import deque


class Solution:
    def minMutation(self, startGene: str, endGene: str, bank: List[str]) -> int:
        bankSet = set(bank)

        if endGene not in bankSet:
            return -1

        queue = deque([(startGene, 0)])

        while queue:
            word, ctr = queue.popleft()

            if word == endGene:
                return ctr

            for i in range(len(word)):
                for ch in "ABCDEFGHIJKLMNOPQRSTUVWXYZ":
                    new_word = word[:i] + ch + word[i + 1 :]
                    if new_word in bankSet:
                        queue.append((new_word, ctr + 1))
                        bankSet.remove(new_word)

        return -1
