/* You are given a large integer represented as an integer array digits, where each digits[i] is the ith digit of the integer. The digits are ordered from most significant to least significant in left-to-right order. The large integer does not contain any leading 0's.

Increment the large integer by one and return the resulting array of digits.



Example 1:

Input: digits = [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.
Incrementing by one gives 123 + 1 = 124.
Thus, the result should be [1,2,4].
Example 2:

Input: digits = [4,3,2,1]
Output: [4,3,2,2]
Explanation: The array represents the integer 4321.
Incrementing by one gives 4321 + 1 = 4322.
Thus, the result should be [4,3,2,2].
Example 3:

Input: digits = [9]
Output: [1,0]
Explanation: The array represents the integer 9.
Incrementing by one gives 9 + 1 = 10.
Thus, the result should be [1,0]. */

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        int n = digits.size();
        // Start from the rightmost digit
        for (int i = n - 1; i >= 0; i--)
        {
            // If the current digit is not 9, simply increment it by 1 and return
            if (digits[i] != 9)
            {
                digits[i]++;
                return digits;
            }
            // If the current digit is 9, set it to 0 and continue to the next digit
            digits[i] = 0;
        }

        // If all digits were 9, we need to add an additional digit at the beginning
        digits.insert(digits.begin(), 1);

        return digits;
    }
};

int main()
{
    vector<int> nums{1, 3, 2, 9};
    vector<int> res;

    Solution s;

    res = s.plusOne(nums);

    for (int x : res)
    {
        cout << x << " ";
    }
}