class Solution:
    def twoSum(self, nums: list[int], target: int) -> list[int]:
        dict = {}
        size = len(nums)

        for i in range(size):
            diff = target - nums[i]

            if diff in dict:
                return [dict[diff], i]
            else:
                dict[nums[i]] = i

        return []
