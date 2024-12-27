/* Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

 

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
Example 2:

Input: nums = [1], k = 1
Output: [1]
  */  

 #include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> mp;
        
        for (int num : nums) {
            mp[num]++;
        }
        
        vector<int> result;
        
        while (k > 0) {
            int maxFreq = -1;
            int maxNum = 0;
            
            for (auto entry : mp) {
                if (entry.second > maxFreq) {
                    maxFreq = entry.second;
                    maxNum = entry.first;
                }
            }
            
            result.push_back(maxNum);
            
            mp.erase(maxNum);
            
            k--;
        }
        
        return result;
    }
};

int main() {
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 2;

    Solution s;
    vector<int> result = s.topKFrequent(nums, k);

    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
