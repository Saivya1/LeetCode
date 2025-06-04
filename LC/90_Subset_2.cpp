/*Given an integer array nums that may contain duplicates, return all possible

(the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.



Example 1:

Input: nums = [1,2,2]
Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]

Example 2:

Input: nums = [0]
Output: [[],[0]]
*/

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<int> curr;
    set<vector<int>> temp_res;

    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        dfs(0, nums);
        vector<vector<int>> res(temp_res.begin(), temp_res.end());
        return res;
    }

private:
    void dfs(int idx, vector<int> &nums)
    {
        if (idx == nums.size())
        {
            temp_res.insert(curr);
            return;
        }

        curr.push_back(nums[idx]);
        dfs(idx + 1, nums);

        curr.pop_back();
        dfs(idx + 1, nums);
    }
};