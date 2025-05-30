/*Given an array nums of distinct integers, return all the possible

. You can return the answer in any order.



Example 1:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

Example 2:

Input: nums = [0,1]
Output: [[0,1],[1,0]]

Example 3:

Input: nums = [1]
Output: [[1]]
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<int>> res;
    vector<vector<int>> permute(vector<int> &nums)
    {

        dfs(nums, 0);
        return res;
    }

    void dfs(vector<int> &nums, int idx)
    {
        if (idx == nums.size())
        {
            res.push_back(nums);
            return;
        }

        for (int i = idx; i < nums.size(); i++)
        {
            swap(nums[idx], nums[i]);
            dfs(nums, idx + 1);
            swap(nums[idx], nums[i]);
        }
    }
};