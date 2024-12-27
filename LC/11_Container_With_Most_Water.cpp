/* You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, such that the container contains the most water.

Return the maximum amount of water a container can store.

Notice that you may not slant the container.



Example 1:


Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49 (8 and 7 are chosen then area = 7*7 where 7 is the height and 7 is the distance between 8 and 7 in the arr)
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.
Example 2:

Input: height = [1,1]
Output: 1 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int max_area = 0;
        int curr_area = 0;
        int l = 0;
        int r = height.size() - 1;

        while (l < r)
        {
            curr_area = (r - l) * min(height[l], height[r]);
            max_area = max(curr_area, max_area);

            if (height[l] < height[r])
            {
                l++;
            }
            else
            {
                r--;
            }
        }

        return max_area;
    }
};

int main()
{
    vector<int> height{1, 8, 6, 2, 5, 4, 8, 3, 7};

    Solution s;

    cout << s.maxArea(height);
}