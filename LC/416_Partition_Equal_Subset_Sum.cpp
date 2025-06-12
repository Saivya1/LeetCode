/*Given an integer array nums, return true if you can partition the array into two subsets such that the sum of the elements in both subsets is equal or false otherwise.



Example 1:

Input: nums = [1,5,11,5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].

Example 2:

Input: nums = [1,2,3,5]
Output: false
Explanation: The array cannot be partitioned into equal sum subsets.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    bool canPartition(vector<int> &nums)
    {
        int n = nums.size();
        int sum = 0;
        int target;
        for (int num : nums)
        {
            sum += num;
        }

        if (sum % 2 == 0)
        {
            target = sum / 2;
        }
        else
        {
            return false;
        }

        vector<bool> dp(target + 1, false);

        dp[0] = true;

        for (int x : nums)
        {
            for (int i = target; i >= x; i--)
            {
                dp[i] = dp[i] || dp[i - x];
            }
        }

        return dp[target];
    }
};