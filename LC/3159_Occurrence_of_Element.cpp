/* You are given an integer array nums, an integer array queries, and an integer x.

For each queries[i], you need to find the index of the queries[i]th occurrence of x in the nums array. If there are fewer than queries[i] occurrences of x, the answer should be -1 for that query.

Return an integer array answer containing the answers to all queries.

 

Example 1:

Input: nums = [1,3,1,7], queries = [1,3,2,4], x = 1

Output: [0,-1,2,-1]

Explanation:

For the 1st query, the first occurrence of 1 is at index 0.
For the 2nd query, there are only two occurrences of 1 in nums, so the answer is -1.
For the 3rd query, the second occurrence of 1 is at index 2.
For the 4th query, there are only two occurrences of 1 in nums, so the answer is -1.
Example 2:

Input: nums = [1,2,3], queries = [10], x = 5

Output: [-1]

Explanation:

For the 1st query, 5 doesn't exist in nums, so the answer is -1.  */


#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

class Solution {
public:
    int findNthOccurrence(vector<int> &nums,int value, int n){
        int occurrence = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==value){
                occurrence++;
                if(occurrence==n){
                    return i;
                }
            }
        }
        return -1;
    }

    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        vector<int> ans;

        for(int i : queries){
            ans.push_back(findNthOccurrence(nums,x,i));
        }

        return ans;
     }

    
};

int main() {
    vector<int> nums{1,3,1,7};
    vector <int> queries{1,3,2,4};
    int x = 1;
    Solution s;
    vector<int> ans;

    ans=s.occurrencesOfElement(nums,queries,x);

    for(int z : ans){
        cout << z;
    }

    
   
}