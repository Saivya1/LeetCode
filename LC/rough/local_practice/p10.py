class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        ctr = 0
        maxCtr = 0
        size = len(s)
        sub = []
        r = 0
        l = 0

        if size == 1:
            return 1

        while r < size:
            if s[r] not in sub:
                sub.append(s[r])
            else:
                while s[r] in sub:
                    sub.remove(s[l])
                    l += 1
                    ctr -= 1
                sub.append(s[r])
            ctr += 1
            r += 1
            maxCtr = max(maxCtr, ctr)

        return maxCtr
