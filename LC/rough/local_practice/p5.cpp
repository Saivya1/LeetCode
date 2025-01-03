#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int l = 0;
        int r = nums.size() - 1;
        int mid;
        while (l <= r)
        {
            mid = l + (r - l) / 2;

            if (nums[mid] == target)
            {
                return mid;
            }
            else if (target > nums[mid])
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }

        return -1;
    }
};