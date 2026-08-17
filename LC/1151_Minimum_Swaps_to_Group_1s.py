class Solution:
    def minSwaps(self, arr):
        numOnes = 0
        numZeroes = 0
        swaps = 999
        size = len(arr)

        for x in arr:
            if x == 1:
                numOnes += 1

        left = 0
        right = numOnes - 1

        for i in range(left,right+1):
            if arr[i] == 0:
                numZeroes += 1

        swaps = numZeroes

        while(right+1 < size):
            if arr[left] == 0:
                numZeroes -= 1
            left += 1
            right += 1

            if arr[right] == 0:
                numZeroes += 1


            swaps = min(swaps,numZeroes)

        return swaps        


class main:
    arr = [0,0,0,1,0,1,1,0,1,0,1]
    swaps = Solution().minSwaps(arr)
    print(swaps)