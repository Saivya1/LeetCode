class Solution:
    def minSubArrayLen(self, target: int, nums: list[int]) -> int:
        size = len(nums)
        left = 0
        sum = 0
        minSub = float("inf")

        for right in range(size):
            sum += nums[right]

            while sum >= target:
                minSub = min(minSub, right - left + 1)
                sum -= nums[left]
                left += 1

        return minSub if minSub != float("inf") else 0
