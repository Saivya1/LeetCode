class Solution:
    def findMaxConsecutiveOnes(self, nums: list[int]) -> int:
        window = 0
        maxWindow = 0

        for x in nums:
            if x == 1:
                window += 1
                maxWindow = max(maxWindow, window)
            else:
                window = 0

        return maxWindow
            
