/* Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time.

 

Example 1:

Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
Example 2:

Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9 */

#include <iostream>
#include <vector>
#include <set>
 using namespace std;

 class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> ms;
        int currLong=1;
        int longest=0;
        

        for(int x : nums){
            ms.insert(x);               
        }
        

        for(int ele : ms){
            if(ms.find(ele+1) != ms.end()){ 
                currLong ++;
            }
            else{
                longest = currLong>longest? currLong : longest;
                currLong=1;
            }
        }

        return longest;
        
    }
};

int main(){
    vector<int> nums{9,1,4,7,3,-1,0,5,8,-1,6};
    Solution s;

    cout << s.longestConsecutive(nums);
}