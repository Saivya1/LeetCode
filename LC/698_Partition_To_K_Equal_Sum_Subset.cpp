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
#include <numeric>

using namespace std;

class Solution
{
public:
    int n;
    int subsetValue;

    bool helper(vector<int> &nums, int k, int mask, int currentSum, vector<int> &dp)
    {
        // Base case: All subsets have been formed
        if (k == 0)
        {
            // Check if all elements of the input array have been used (mask is full)
            return mask == (1 << n) - 1;
        }

        // If the current subset has reached the target value, move on to the next subset
        if (currentSum == subsetValue)
        {
            return helper(nums, k - 1, mask, 0, dp);
        }

        // Check if the current state has been memoized
        if (dp[mask] != -1)
        {
            return dp[mask];
        }

        bool ans = false;
        for (int i = 0; i < n; i++)
        {
            // Skip elements that have already been used in the current subset
            if (mask & (1 << i))
            {
                continue;
            }

            // Try adding the current element to the current subset if it doesn't exceed the target value
            if (currentSum + nums[i] <= subsetValue)
            {
                int newMask = mask | (1 << i); // Set the ith bit of the mask to mark the element as used
                ans = ans || helper(nums, k, newMask, currentSum + nums[i], dp);
                newMask ^= (1 << i); // Clear the ith bit to backtrack and try other elements
            }
        }

        // Memoize the result for the current state
        return dp[mask] = ans;
    }

    // Main function to check if the array can be partitioned into k subsets with equal sum
    bool canPartitionKSubsets(vector<int> &nums, int k)
    {
        n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        subsetValue = sum / k;

        // If the total sum is not divisible by k, partition is not possible
        if (sum % k != 0)
        {
            return false;
        }

        vector<int> dp((1 << n) - 1, -1); // Memoization array to store results for subsets
        return helper(nums, k, 0, 0, dp);
    }
};
