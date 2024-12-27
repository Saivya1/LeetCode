/* Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Note that you must do this in-place without making a copy of the array.



Example 1:

Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]
Example 2:

Input: nums = [0]
Output: [0] */

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int j = 0;
        int ctr = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != 0)
            {
                nums[j] = nums[i];
                j++;
            }
            else
            {
                ctr++;
            }
        }
        for (int k = 0; k < ctr; k++)
        {
            nums.pop_back();
        }

        for (int k = 0; k < ctr; k++)
        {
            nums.push_back(0);
        }
    }
};

int main()
{
    vector<int> nums{0, 1, 0, 3, 12};

    Solution s;

    s.moveZeroes(nums);

    for (int x : nums)
    {
        cout << x << " ";
    }
}