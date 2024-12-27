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
    vector<int> subarraySum(vector<int>& nums, int k) {

        vector<int> ans;
        int sum=0;
        int ctr=0;
        for(int i=0 ; i<nums.size(); i++){
            sum=nums[i];
            ctr += (nums[i] == k) ? 1 : 0;
            for(int j=i+1 ; j<nums.size();j++){
                sum += nums[j];
                if(sum==k){
                    ctr++;
                } 
            }
        }
        ans.push_back(ctr);
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