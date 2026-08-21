class Solution:
    def shipWithinDays(self, weights: List[int], days: int) -> int:
        left = max(weights)
        right = sum(weights)

        while left < right:

            mid = left + (right - left) // 2

            currSum = 0
            requiredDays = 1
            for weight in weights:
                if currSum + weight > mid:
                    requiredDays += 1
                    currSum = 0
                currSum += weight

            if requiredDays > days:
                left = mid + 1
            else:
                right = mid

        return left
