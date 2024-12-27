/* Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).



Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5. */

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> merged;
        int i = 0;
        int j = 0;

        // Merge the two arrays
        while (i < nums1.size() && j < nums2.size())
        {
            if (nums1[i] < nums2[j])
            {
                merged.push_back(nums1[i]);
                i++;
            }
            else
            {
                merged.push_back(nums2[j]);
                j++;
            }
        }

        // If remaining elements in nums1
        while (i < nums1.size())
        {
            merged.push_back(nums1[i]);
            i++;
        }

        // If remaining elements in nums2
        while (j < nums2.size())
        {
            merged.push_back(nums2[j]);
            j++;
        }

        if (merged.size() % 2 == 0)
        {
            int mid1 = merged[merged.size() / 2];
            int mid2 = merged[(merged.size() / 2) - 1];

            return (static_cast<double>(mid1) + mid2) / 2.0;
        }
        else
        {
            return static_cast<double>(merged[merged.size() / 2]);
        }
    }
};

int main()
{
    vector<int> nums1{1, 3};
    vector<int> nums2{2, 4};
    Solution s;

    cout << s.findMedianSortedArrays(nums1, nums2);
}