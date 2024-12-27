#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        if (matrix.empty() || matrix[0].empty())
        {
            return false;
        }
        int m = matrix.size();
        int n = matrix[0].size();

        int l = 0;
        int r = m * n - 1;
        int mid;
        int mid_value;
        while (l <= r)
        {
            mid = l + (r - l / 2);
            mid_value = matrix[mid / n][mid % n];

            if (mid_value == target)
            {
                return true;
            }
            else if (mid_value > target)
            {
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        return false;
    }
};