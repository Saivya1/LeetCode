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
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        int size_s1 = s1.size();
        int size_s2 = s2.size();

        if (size_s1 > size_s2)
        {
            return false;
        }

        unordered_map<char, int> freqs1;

        for (char c : s1)
        {
            freqs1[c]++;
        }

        int ctr = 0;

        for (int i = 0; i < size_s2; i++)
        {
            for (int j = 0; j < size_s1; j++)
            {
                if (freqs1.find(s2[i]) != freqs1.end())
                {
                    ctr++;
                }
            }
        }
    }
};