/* Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

A subarray is a contiguous non-empty sequence of elements within an array.

 

Example 1:

Input: nums = [1,1,1], k = 2
Output: 2
Example 2:

Input: nums = [1,2,3], k = 3
Output: 2  

Input: arr[] = {1, 4, 20, 3, 10, 5}, sum = 33
Output: Sum found between indexes 2 and 4
Explanation: Sum of elements between indices 2 and 4 is 20 + 3 + 10 = 33

*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> um;
        int prefixSum = 0, ans = 0;

        um[0] = 1; // To handle cases where prefixSum equals `k`

        for (int num : nums) {
            prefixSum += num;

            if (um.find(prefixSum - k) != um.end()) {
                ans += um[prefixSum - k];
            }

            um[prefixSum]++;
        }

        return ans;
    }
};

int main(){
    vector<int> nums{1,2,3};
    vector<int> ans;
    int k=3;

    Solution s;

    ans = s.subarraySum(nums,k);

    for(int z : ans){
        cout << z;
    }


}