import math


class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        left = 1
        right = max(piles)

        while left < right:
            mid = left + (right - left) // 2
            time = 0
            for x in piles:
                time += math.ceil(x / mid)

            if time > h:
                left = mid + 1
            else:
                right = mid

        return left
