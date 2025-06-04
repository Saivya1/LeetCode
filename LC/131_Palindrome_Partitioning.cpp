/*Given a string s, partition s such that every of the partition is a

. Return all possible palindrome partitioning of s.



Example 1:

Input: s = "aab"
Output: [["a","a","b"],["aa","b"]]

Example 2:

Input: s = "a"
Output: [["a"]]
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<string> curr;
    vector<vector<string>> res;

    vector<vector<string>> partition(string s)
    {
        dfs(s, 0);
        return res;
    }

private:
    bool isPalindrome(string s, int start, int end)
    {
        while (start < end)
        {
            if (s[start++] != s[end--])
            {
                return false;
            }
        }
        return true;
    }

    void dfs(string s, int idx)
    {
        if (idx == s.size())
        {
            res.push_back(curr);
            return;
        }

        for (int end = idx; end < s.size(); end++)
        {
            if (isPalindrome(s, idx, end))
            {
                curr.push_back(s.substr(idx, end - idx + 1));
                dfs(s, end + 1);
                curr.pop_back();
            }
        }
    }
};