/*Given an integer array nums of unique elements, return all possible subsets

(the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.



Example 1:

Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

Example 2:

Input: nums = [0]
Output: [[],[0]]
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> current;
    vector<vector<int>> res;

    vector<vector<int>> subsets(vector<int> &nums)
    {
        if (nums.size() == 0)
        {
            return res;
        }
        dfs(0, nums);
        return res;
    }

private:
    void dfs(int i, vector<int> &nums)
    {
        if (i == nums.size())
        {
            res.push_back(current);
            return;
        }

        current.push_back(nums[i]);
        dfs(i + 1, nums);

        current.pop_back();
        dfs(i + 1, nums);
    }
};