class Solution:
    def subarraySum(self, nums: list[int], k: int) -> int:
        prefixSum = 0
        um = {}
        ans = 0

        um[0] = 1
        for num in nums:
            prefixSum += num

            if prefixSum - k in um:
                ans += um[prefixSum - k]

            if prefixSum in um:
                um[prefixSum] += 1
            else:
                um[prefixSum] = 1

        return ans
