/* Given a string s, find the length of the longest
substring
 without repeating characters.



Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
  */

#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_map<char, int> um;
        int ctr = 0;
        int max_ctr = 0;
        int copy;
        int j = 0;

        for (int i = 0; i < s.size(); i++)
        {

            if (um[s[i]] == 0)
            {

                um[s[i]]++;
                ctr++;
                max_ctr = max(ctr, max_ctr);
            }
            else
            {
                j++;
                ctr = 0;
                um.clear();
                i = j - 1;
            }
        }

        return max_ctr;
    }
};

int main()
{
    string s = "abcabcbb";
    string s2 = "pwwkew";

    Solution s1;

    cout << s1.lengthOfLongestSubstring(s);
    cout << endl;
    cout << s1.lengthOfLongestSubstring(s2);
}