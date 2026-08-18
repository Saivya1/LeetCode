class NumArray:

    def __init__(self, nums: List[int]):
        prefixSum = 0
        self.prefixArr = []

        for x in nums:
            prefixSum += x
            self.prefixArr.append(prefixSum)

    def sumRange(self, left: int, right: int) -> int:
        return self.prefixArr[right] - (self.prefixArr[left - 1] if left > 0 else 0)


# Your NumArray object will be instantiated and called as such:
# obj = NumArray(nums)
# param_1 = obj.sumRange(left,right)
