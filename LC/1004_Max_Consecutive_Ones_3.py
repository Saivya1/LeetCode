class Solution:
    def longestOnes(self, nums: list[int], k: int) -> int:
        maxWindow = 0
        numZeroes = 0
        left = 0 
        right = 0
        size = len(nums)

        while right < size:
            if nums[right] == 0:
                numZeroes += 1

            while numZeroes > k:
                if nums[left] == 0:
                    numZeroes -= 1
                left += 1

            maxWindow = max(maxWindow, right - left + 1)
            right += 1
        return maxWindow
