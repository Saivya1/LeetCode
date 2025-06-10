/*Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.

Note that the same word in the dictionary may be reused multiple times in the segmentation.



Example 1:

Input: s = "leetcode", wordDict = ["leet","code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".

Example 2:

Input: s = "applepenapple", wordDict = ["apple","pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
Note that you are allowed to reuse a dictionary word.

Example 3:

Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
Output: false
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>

using namespace std;

class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        int n = s.size();

        set<string> dict;
        for (auto w : wordDict)
            dict.insert(w);

        vector<bool> dp(n + 1, false);
        dp[0] = true; // You can make empty string with any wordDict

        // From every i position check if you can make word ending here
        for (int i = 0; i < n; i++)
        {
            // If we can make a word from j->i
            // We need to check if we can make a word till j first
            for (int j = i; j >= 0; j--)
            {
                string curr = s.substr(j, i - j + 1); // pos,noOfChars

                if (dict.find(curr) != dict.end())
                    dp[i + 1] = dp[i + 1] || dp[j]; // dp[j] means can be make words before j(dp is 1 indexed)

                if (dp[i + 1])
                    break;
            }
        }

        return dp[n];
    }
};