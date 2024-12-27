/* Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.



Example 1:

Input: nums = [3,2,3]
Output: 3
Example 2:

Input: nums = [2,2,1,1,1,2,2]
Output: 20 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        unordered_map<int, int> um;

        int n = nums.size() / 2;

        for (int x : nums)
        {
            um[x]++;
            if (um[x] > n)
            {
                return x;
            }
        }

        return -1;
    }
};

int main()
{
    vector<int> nums{3, 2, 3};

    Solution s;

    cout << s.majorityElement(nums);
}