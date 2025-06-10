/*Given an integer array nums, find a

that has the largest product, and return the product.

The test cases are generated so that the answer will fit in a 32-bit integer.



Example 1:

Input: nums = [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.

Example 2:

Input: nums = [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int n = nums.size();
        int maxProd = nums[0];
        int currMax = nums[0], currMin = nums[0];

        for (int i = 1; i < n; ++i)
        {
            if (nums[i] < 0)
            {
                swap(currMax, currMin); // because negative flips max/min
            }

            currMax = max(nums[i], currMax * nums[i]);
            currMin = min(nums[i], currMin * nums[i]);

            maxProd = max(maxProd, currMax);
        }

        return maxProd;
    }
};
