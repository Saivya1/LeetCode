/* Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.



Example 1:

Input: nums = [1,2,3,1]
Output: true
Example 2:

Input: nums = [1,2,3,4]
Output: false
Example 3:

Input: nums = [1,1,1,3,3,4,3,2,4,2]
Output: true */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        unordered_map<int, int> um;

        for (int x : nums)
        {
            um[x]++;
            if (um[x] > 1)
            {
                return true;
            }
        }
        return false;
    }
};

int main()
{

    vector<int> nums{1, 2, 3, 1};

    Solution s;

    cout << s.containsDuplicate(nums);
}