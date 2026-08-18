class Solution:
    def minSubArrayLen(self, target: int, nums: list[int]) -> int:
        left = 0
        windowSum = 0
        minLen = float("inf")

        for right in range(len(nums)):
            windowSum += nums[right]

            while windowSum >= target:
                minLen = min(minLen, right - left + 1)
                windowSum -= nums[left]
                left += 1

        return int(minLen) if minLen != float("inf") else 0
