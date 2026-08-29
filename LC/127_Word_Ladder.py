from collections import deque


class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        wordSet = set(wordList)
        if endWord not in wordList:
            return 0
        queue = deque([(beginWord, 1)])

        while queue:
            word, ctr = queue.popleft()

            if word == endWord:
                return ctr

            for i in range(len(word)):
                for ch in "abcdefghijklmnopqrstuvwxyz":
                    new_word = word[:i] + ch + word[i + 1 :]

                    if new_word in wordSet:
                        queue.append((new_word, ctr + 1))
                        wordSet.remove(new_word)
        return 0
