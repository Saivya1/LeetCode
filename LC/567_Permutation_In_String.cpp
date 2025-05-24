/*Given two strings s1 and s2, return true if s2 contains a
permutation
of s1, or false otherwise.

In other words, return true if one of s1's permutations is the substring of s2.



Example 1:

Input: s1 = "ab", s2 = "eidbaooo"
Output: true
Explanation: s2 contains one permutation of s1 ("ba").

Example 2:

Input: s1 = "ab", s2 = "eidboaoo"
Output: false
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        int len1 = s1.size(), len2 = s2.size();
        if (len1 > len2)
            return false;

        vector<int> freq1(26, 0), freq2(26, 0);

        for (int i = 0; i < len1; i++)
        {
            freq1[s1[i] - 'a']++;
            freq2[s2[i] - 'a']++;
        }

        if (freq1 == freq2)
            return true;

        for (int i = len1; i < len2; i++)
        {
            freq2[s2[i] - 'a']++;
            freq2[s2[i - len1] - 'a']--;

            if (freq1 == freq2)
                return true;
        }

        return false;
    }
};
