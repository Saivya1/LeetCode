/* Given two integer arrays nums1 and nums2, return an array of their
intersection
. Each element in the result must be unique and you may return the result in any order.



Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2]
Example 2:

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [9,4]
Explanation: [4,9] is also accepted. */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_map<int, int> um;
        vector<int> res;

        for (int x : nums1)
        {
            um[x]++;
        }

        for (int y : nums2)
        {
            if (um.count(y) == 1)
            {
                um.erase(y);
                res.push_back(y);
            }
        }

        return res;
    }
};

int main()
{
    vector<int> nums1{1, 2, 2, 1};
    vector<int> nums2{2, 2};
    vector<int> res;

    Solution s;

    res = s.intersection(nums1, nums2);

    for (int x : res)
    {
        cout << x << " ";
    }
}