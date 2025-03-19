/*Given a binary array nums, return the maximum length of a contiguous subarray with an equal number of 0 and 1.

 

Example 1:

Input: nums = [0,1]
Output: 2
Explanation: [0, 1] is the longest contiguous subarray with an equal number of 0 and 1.

Example 2:

Input: nums = [0,1,0]
Output: 2
Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>


using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) nums[i] = -1;     // Convert 0 to -1
        }

        unordered_map<int, int> um;
        um[0] = -1;

        int prefixSum = 0, ans = 0;

        for (int i = 0; i < nums.size(); i++) {
            prefixSum += nums[i];              // Calculate prefixSum in the same loop instead of a separate vector

            if (um.find(prefixSum) != um.end()) {
                ans = max(ans, i - um[prefixSum]);      // If two values same in prefixSum then the difference of the indices is the ans
            } else {
                um[prefixSum] = i;                      // If same value  not found then add into um
            }
        }

        return ans;
    }
};
