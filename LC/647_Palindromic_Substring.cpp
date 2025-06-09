/*Given a string s, return the number of palindromic substrings in it.

A string is a palindrome when it reads the same backward as forward.

A substring is a contiguous sequence of characters within the string.



Example 1:

Input: s = "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".

Example 2:

Input: s = "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int countSubstrings(string s)
    {
        int ctr = 0;
        int n = s.length();

        if (n <= 1)
        {
            return n;
        }

        vector<vector<bool>> dp(n, vector<bool>(n, false));

        for (int i = 0; i < n; i++)
        {
            ctr++;
            dp[i][i] = true;
        }

        for (int j = 1; j < n; j++)
        {
            for (int i = 0; i < j; i++)
            {
                if (s[i] == s[j] && (j - i + 1 <= 2 || dp[i + 1][j - 1]))
                {
                    ctr++;
                    dp[i][j] = true;
                }
            }
        }
        return ctr;
    }
};