class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        numSet = set(nums)
        ctr = 0
        maxctr = 0

        for nums in numSet:
            if nums - 1 not in numSet:
                ctr = 1

                while nums + ctr in numSet:
                    ctr += 1

                maxctr = max(ctr, maxctr)

        return maxctr
