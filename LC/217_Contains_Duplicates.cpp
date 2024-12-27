/* Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

 

Example 1:

Input: nums = [1,2,3,1]
Output: true
Example 2:

Input: nums = [1,2,3,4]
Output: false
Example 3:

Input: nums = [1,1,1,3,3,4,3,2,4,2]
Output: true */


#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
class Solution {
public:
    bool containsDuplicate(std::vector<int>& nums) {
        unordered_set<int> seen;
        for (int num : nums) {
            if (seen.count(num)) {
                return true;
            }
            seen.insert(num);
        }
        return false;
    }
};

int main(){

    vector<int> nums{1,5,-2,-4,0};
    Solution s;
    cout << s.containsDuplicate(nums);


}