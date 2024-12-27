/* Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.

 

Example 1:
               0 1 2 3 
Input: nums = [1,2,3,4]
Output: [24,12,8,6]
Example 2:

Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0] */

#include <iostream>
#include <vector> 
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        /* Inefficient
        int pro=1;
        int temp;
        for(int j = 0 ; j<nums.size() ; j++){
                temp = nums[j];
                nums[j]=1;
            for(int i = 0; i<nums.size() ; i++){
                pro *= nums[i];
            }
        
            nums[j]=temp;
            ans.push_back(pro);
            pro=1;
        }
        
        return ans; */

        
        int n = nums.size();
        vector<int> ans(n, 1);
        int left_product = 1;
        int right_product = 1;

        // Calculate left product for each element except itself
        for (int i = 0; i < n; ++i) {
            ans[i] = left_product;
            left_product *= nums[i];
        }

        // Calculate right product for each element except itself and multiply
        for (int i = n - 1; i >= 0; --i) {
            ans[i] *= right_product;
            right_product *= nums[i];
        }

        return ans;
    }
};


int main(){
    vector<int> nums{1,2,3,4};
    vector<int> ans;

    Solution s;

    ans = s.productExceptSelf(nums);

    for ( int x : ans){
        cout << x << endl;
    }    

}