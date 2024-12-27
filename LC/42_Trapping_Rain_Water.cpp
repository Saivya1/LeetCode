/* Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.



Example 1:


Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
Example 2:

Input: height = [4,2,0,3,2,5]
Output: 9 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int trap(vector<int> &height)
    {
        int n = height.size();
        if (n == 0)
            return 0;

        int left = 0, right = n - 1;
        int left_max = 0, right_max = 0;
        int water_trapped = 0;

        while (left < right)
        {
            if (height[left] < height[right])
            {
                if (height[left] >= left_max)
                {
                    left_max = height[left];
                }
                else
                {
                    water_trapped += left_max - height[left];
                }
                left++;
            }
            else
            {
                if (height[right] >= right_max)
                {
                    right_max = height[right];
                }
                else
                {
                    water_trapped += right_max - height[right];
                }
                right--;
            }
        }

        return water_trapped;
    }
};

int main()
{
    Solution solution;
    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << "Trapped water: " << solution.trap(height) << endl; // Output: 6

    return 0;
}
