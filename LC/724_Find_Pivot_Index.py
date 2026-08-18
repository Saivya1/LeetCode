class Solution:
    def pivotIndex(self, nums: List[int]) -> int:
        total = sum(nums)
        size = len(nums)
        leftSum = 0

        for i in range(size):
            rightSum = total - leftSum - nums[i]

            if leftSum == rightSum:
                return i

            leftSum += nums[i]

        return -1
