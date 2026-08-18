class Solution:
    def findMaxLength(self, nums: list[int]) -> int:
        prefixSum = 0
        maxLen = 0
        um = {0: -1}

        for i in range(len(nums)):
            if nums[i] == 0:
                prefixSum -= 1
            else:
                prefixSum += 1

            if prefixSum in um:
                maxLen = max(maxLen, i - um[prefixSum])
            else:
                um[prefixSum] = i

        return maxLen
