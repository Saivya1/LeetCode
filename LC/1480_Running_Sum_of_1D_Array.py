class Solution:
    def runningSum(self, nums: list[int]) -> list[int]:
        prefixSum = 0
        res = []
        for x in nums:
            prefixSum += x
            res.append(prefixSum)

        return res
