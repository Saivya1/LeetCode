/* Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".



Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings. */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        if (strs.empty())
        {
            return "";
        }

        string prefix = strs[0];

        for (int i = 1; i < strs.size(); ++i)
        {
            while (strs[i].find(prefix) != 0)
            {
                prefix = prefix.substr(0, prefix.length() - 1);
                if (prefix.empty())
                {
                    return "";
                }
            }
        }

        return prefix;
    }
};

int main()
{
    Solution sol;

    vector<string> strs1 = {"flower", "flow", "flight"};
    cout << "Example 1: " << sol.longestCommonPrefix(strs1) << endl;

    vector<string> strs2 = {"dog", "racecar", "car"};
    cout << "Example 2: " << sol.longestCommonPrefix(strs2) << endl;

    return 0;
}
