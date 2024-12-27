/* Given an array of strings strs, group the anagrams together. You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

 

Example 1:

Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
Example 2:

Input: strs = [""]
Output: [[""]]
Example 3:

Input: strs = ["a"]
Output: [["a"]]
  */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string , vector<string>> um;
        vector<vector<string>> ans;
        string sorted;

        for(string s : strs){
            sorted = s;
            sort(sorted.begin(),sorted.end());
            um[sorted].push_back(s);
        }

        for( auto grp : um){
            ans.push_back(grp.second);
        }

        return ans;
    
    }
};

int main(){
    vector<string> strs{"eat","tea","tan","ate","nat","bat"};
    vector<vector<string>> ans;
    
    
    Solution s;

     ans = s.groupAnagrams(strs);

    

     for ( auto group : ans) {
        for ( auto word : group) {
            cout << word << " ";
        }
        cout << endl;
    }
}
