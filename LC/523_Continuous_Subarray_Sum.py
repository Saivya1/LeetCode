class Solution:
    def checkSubarraySum(self, nums: list[int], k: int) -> bool:
        size = len(nums)
        right = 0
        prefixSum = 0
        prefixArr = []
        um = {0: -1}

        for x in nums:
            prefixSum += x
            prefixArr.append(prefixSum)

        for right in range(size):
            rem = prefixArr[right] % k
            if rem in um:
                if right - um[rem] >= 2:
                    return True

            else:
                um[rem] = right

        return False
