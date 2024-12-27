/* Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

You must implement a solution with a linear runtime complexity and use only constant extra space.

Example 1:

Input: nums = [2,2,1]
Output: 1
Example 2:

Input: nums = [4,1,2,1,2]
Output: 4
Example 3:

Input: nums = [1]
Output: 1 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        unordered_map<int, int> um;
        for (int x : nums)
        {
            um[x]++;
        }

        for (auto it = um.begin(); it != um.end(); it++)
        {
            if (it->second == 1)
            {
                return it->first;
            }
        }

        return -1;
    }
};

int main()
{
    vector<int> nums{2, 2, 1};

    Solution s;

    cout << s.singleNumber(nums);
}