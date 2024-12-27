/* You are given an m x n integer matrix matrix with the following two properties:

Each row is sorted in non-decreasing order.
The first integer of each row is greater than the last integer of the previous row.
Given an integer target, return true if target is in matrix or false otherwise.

You must write a solution in O(log(m * n)) time complexity.



Example 1:


Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true
Example 2:


Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
Output: false */

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    //     bool searchMatrix(vector<vector<int>> &matrix, int target)
    //     {
    //         vector<int> nums;

    //         for (auto grp : matrix)
    //         {
    //             for (int n : grp)
    //             {
    //                 nums.push_back(n);
    //             }
    //         }

    //         int l = 0;
    //         int r = nums.size() - 1;
    //         int mid = 0;

    //         while (l <= r)
    //         {
    //             mid = (l + r) / 2;
    //             if (nums[mid] == target)
    //             {
    //                 return true;
    //             }
    //             else if (nums[mid] > target)
    //             {
    //                 r = mid - 1;
    //             }
    //             else
    //             {
    //                 l = mid + 1;
    //             }
    //         }
    //         return false;
    //     }
    //                                           Better Solution

    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        if (matrix.empty() || matrix[0].empty())
        {
            return false;
        }

        int m = matrix.size();
        int n = matrix[0].size();
        int left = 0;
        int right = m * n - 1;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            int mid_value = matrix[mid / n][mid % n];

            if (mid_value == target)
            {
                return true;
            }
            else if (mid_value < target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }

        return false;
    }
};

int main()
{
    vector<vector<int>> matrix = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    int target = 3;

    Solution s;
    bool result = s.searchMatrix(matrix, target);

    cout << (result ? "Target found" : "Target not found") << endl;
    return 0;
}