/* Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.



Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]
Example 3:

Input: nums = [3,3], target = 6
Output: [0,1] */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> num_map;

        for (int i = 0; i < nums.size(); i++)
        {
            int diff = target - nums[i];
            if (num_map.find(diff) != num_map.end())
            {
                return {num_map[diff], i};
            }
            num_map[nums[i]] = i;
        }

        return {};
    }
};

int main()
{
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    Solution s;
    vector<int> res = s.twoSum(nums, target);

    for (int x : res)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
