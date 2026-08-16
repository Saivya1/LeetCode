
# [1, 0, 1, 0, 1]

class Solution:
    def minSwaps(self, arr) -> int:
        numOnes = 0
        numZeroes = 0
        swapsZeroes = 0
        swapsOnes = 0
        for num in arr:
            if num == 1:
                numOnes += 1
            else:
                swapsZeroes += numOnes
        for num in arr:
            if num == 0:
                numZeroes += 1
            else:
                swapsOnes += numZeroes

        return min(swapsOnes,swapsZeroes)
            
