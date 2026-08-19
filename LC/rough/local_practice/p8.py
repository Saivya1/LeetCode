class Solution:
    def subarraySum(self, nums: list[int], k: int) -> int:
        size = len(nums)
        um = {0: 1}
        ans = 0
        prefixSum = 0

        for i in range(size):
            prefixSum += nums[i]

            if prefixSum - k in um:
                ans += um[prefixSum - k]

            um[prefixSum] = um.get(prefixSum, 0) + 1

        return ans
