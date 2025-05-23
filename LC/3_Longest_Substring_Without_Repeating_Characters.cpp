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
#include <unordered_set>

using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int left = 0;
        int maxLength = 0;
        unordered_set<char> charSet;

        for (int right = 0; right < s.length(); right++)
        {
            while (charSet.find(s[right]) != charSet.end())
            {
                charSet.erase(s[left]);
                left++;
            }

            charSet.insert(s[right]);
            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
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