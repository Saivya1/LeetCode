/*Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order.



Example 1:

Input: nums = [1,1,2]
Output:
[[1,1,2],
 [1,2,1],
 [2,1,1]]

Example 2:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
*/

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution
{
public:
    set<vector<int>> temp_res;

    vector<vector<int>> permuteUnique(vector<int> &nums)
    {

        dfs(0, nums);
        vector<vector<int>> res(temp_res.begin(), temp_res.end());
        return res;
    }

private:
    void dfs(int idx, vector<int> &nums)
    {
        if (idx == nums.size())
        {
            temp_res.insert(nums);
            return;
        }

        for (int i = idx; i < nums.size(); i++)
        {
            swap(nums[idx], nums[i]);
            dfs(idx + 1, nums);
            swap(nums[idx], nums[i]);
        }
    }
};