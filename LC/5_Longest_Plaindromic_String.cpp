/*Given a string s, return the longest palindromic substring in s.



Example 1:

Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.

Example 2:

Input: s = "cbbd"
Output: "bb"
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    string longestPalindrome(string s)
    {
        int n = s.length(); // Get the length of the input string
        if (n <= 1)
            return s; // If the string is empty or has one character, return it directly

        int start = 0, max_len = 1; // Start index and max length of longest palindrome found
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        // dp[i][j] will be true if the substring s[i..j] is a palindrome

        // Step 1: All substrings of length 1 are palindromes
        for (int i = 0; i < n; ++i)
        {
            dp[i][i] = true;
        }

        // Step 2: Check all substrings of length >= 2
        for (int j = 1; j < n; j++)
        {
            for (int i = 0; i < j; i++)
            {
                // A substring s[i..j] is a palindrome if:
                // - s[i] == s[j] (characters at both ends match)
                // - and the inner substring s[i+1..j-1] is also a palindrome, OR the length is <= 2 (like "aa" or "aba")
                if (s[i] == s[j] && (j - i <= 2 || dp[i + 1][j - 1]))
                {
                    dp[i][j] = true;

                    // Update longest palindrome if this one is longer
                    if (j - i + 1 > max_len)
                    {
                        max_len = j - i + 1; // Update maximum length
                        start = i;           // Update start index
                    }
                }
            }
        }

        // Return the longest palindrome substring found
        return s.substr(start, max_len);
    }
};
