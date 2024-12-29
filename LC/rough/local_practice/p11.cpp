#include <iostream>
#include <unordered_set>
#include <string>

using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        if (s.empty())
            return 0;
        if (s.size() == 1)
            return 1;

        unordered_set<char> us; // To store unique characters
        int max_ctr = 0;        // To store the maximum length
        int start = 0;          // Left pointer of the window

        for (int end = 0; end < s.size(); end++)
        {
            // If a duplicate is found, move the start pointer
            while (us.find(s[end]) != us.end())
            {
                us.erase(s[start]);
                start++;
            }

            // Add the current character to the set
            us.insert(s[end]);

            // Update the maximum length
            max_ctr = max(max_ctr, end - start + 1);
        }

        return max_ctr;
    }
};
