#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <algorithm>
#include <queue>

using namespace std;

class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int n = nums.size();
        int minlen = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            int sum = nums[i];
            int len = 1;
            for (int j = i + 1; j < n; j++)
            {
                sum += nums[j];
                len++;

                if (sum > target)
                {
                    continue;
                }

                if (sum == target)
                {
                    minlen = min(minlen, len);
                }
            }
        }

        return minlen;
    }
};