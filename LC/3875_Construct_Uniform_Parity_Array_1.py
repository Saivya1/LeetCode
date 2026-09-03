class Solution:
    def uniformArray(self, nums1: list[int]) -> bool:
        return True


# if every element of nums1 is even or every element is odd then we can simply copy num1 to num2 to have uniform parity
# if nums1 is a mix of odd and even numbers then for every even number we can subtract an odd number from it to get an odd number becuase even-odd = odd
