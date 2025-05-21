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

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {

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
        vector<int> left(n, 1);
        vector<int> right(n, 1);
        vector<int> ans(n);

        for (int i = 1; i < n; ++i)
        {
            left[i] = left[i - 1] * nums[i - 1];
        }

        for (int i = n - 2; i >= 0; --i)
        {
            right[i] = right[i + 1] * nums[i + 1];
        }

        for (int i = 0; i < n; ++i)
        {
            ans[i] = left[i] * right[i];
        }

        return ans;
    }
};

int main()
{
    vector<int> nums{1, 2, 3, 4};
    vector<int> ans;

    Solution s;

    ans = s.productExceptSelf(nums);

    for (int x : ans)
    {
        cout << x << endl;
    }
}