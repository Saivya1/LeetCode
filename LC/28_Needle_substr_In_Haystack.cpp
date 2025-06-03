/* Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.



Example 1:

Input: haystack = "sadbutsad", needle = "sad"
Output: 0
Explanation: "sad" occurs at index 0 and 6.
The first occurrence is at index 0, so we return 0.
Example 2:

Input: haystack = "leetcode", needle = "leeto"
Output: -1
Explanation: "leeto" did not occur in "leetcode", so we return -1. */

#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        if (needle.empty())
        {
            return 0;
        }

        int n = haystack.length();
        int m = needle.length();

        for (int i = 0; i <= n - m; i++)
        {
            if (haystack.substr(i, m) == needle)
            {
                return i;
            }
        }

        return -1;
    }
};

int main()
{
    Solution sol;
    std::string haystack1 = "sadbutsad";
    std::string needle1 = "sad";
    std::cout << "Example 1: " << sol.strStr(haystack1, needle1) << std::endl;

    std::string haystack2 = "leetcode";
    std::string needle2 = "leeto";
    std::cout << "Example 2: " << sol.strStr(haystack2, needle2) << std::endl;

    return 0;
}
