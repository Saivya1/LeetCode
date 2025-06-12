/*Given an integer array nums and an integer k, return true if it is possible to divide this array into k non-empty subsets whose sums are all equal.



Example 1:

Input: nums = [4,3,2,3,5,2,1], k = 4
Output: true
Explanation: It is possible to divide it into 4 subsets (5), (1, 4), (2,3), (2,3) with equal sums.

Example 2:

Input: nums = [1,2,3,4], k = 3
Output: false
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    bool canPartitionKSubsets(vector<int> &nums, int k)
    {
        int sum = 0, target;

        for (int num : nums)
        {
            sum += num;
        }

        target = sum / 4;

        if (sum % k != 0)
        {
            return false;
        }

        vector<bool> dp(target + 1, false);

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