class Solution:
    def minWindow(self, s: str, t: str) -> str:
        m = len(s)
        n = len(t)

        if n > m:
            return ""

        um = {}

        for c in t:
            um[c] = um.get(c, 0) + 1

        left = 0
        right = 0
        ctr = 0
        minLen = float("inf")
        start = 0

        while right < m:

            if s[right] in um:
                if um[s[right]] > 0:
                    ctr += 1

                um[s[right]] -= 1

            while ctr == n:

                if right - left + 1 < minLen:
                    minLen = right - left + 1
                    start = left

                if s[left] in um:
                    um[s[left]] += 1

                    if um[s[left]] > 0:
                        ctr -= 1

                left += 1

            right += 1

        if minLen == float("inf"):
            return ""

        return s[start : start + minLen]
