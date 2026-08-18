class Solution:
    def subarraysDivByK(self, nums: list[int], k: int) -> int:
        prefixSum = 0
        prefixArr = []
        um = {0: 1}
        res = 0

        for x in nums:
            prefixSum += x
            prefixArr.append(prefixSum)

        for x in prefixArr:
            remainder = x % k
            if remainder in um:
                res += um[remainder]

            um[remainder] = um.get(remainder, 0) + 1

        return res
