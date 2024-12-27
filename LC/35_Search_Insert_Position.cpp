/* Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [1,3,5,6], target = 5
Output: 2
Example 2:

Input: nums = [1,3,5,6], target = 2
Output: 1
Example 3:

Input: nums = [1,3,5,6], target = 7
Output: 4 */




#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int binarySearch(vector<int>& nums, int key, int low, int high) {
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == key) {
                return mid;
            } else if (nums[mid] < key) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return low; 
    }

    int searchInsert(vector<int>& nums, int key) {
        return binarySearch(nums, key, 0, nums.size() - 1);
    }
};

int main() {
    Solution s1;
    vector<int> nums{1, 3, 5, 6};
    
    cout << s1.searchInsert(nums, 5) << endl;
    cout << s1.searchInsert(nums, 2) << endl; 
    cout << s1.searchInsert(nums, 7) << endl; 
    cout << s1.searchInsert(nums, 0) << endl; 

    return 0;
}
