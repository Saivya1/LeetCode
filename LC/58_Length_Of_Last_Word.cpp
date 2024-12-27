/* Given a string s consisting of words and spaces, return the length of the last word in the string.

A word is a maximal
substring
 consisting of non-space characters only.



Example 1:

Input: s = "Hello World"
Output: 5
Explanation: The last word is "World" with length 5.
Example 2:

Input: s = "   fly me   to   the moon  "
Output: 4
Explanation: The last word is "moon" with length 4.
Example 3:

Input: s = "luffy is still joyboy"
Output: 6
Explanation: The last word is "joyboy" with length 6.
  */

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        int r = s.size() - 1;
        int ctr = 0;
        if (s.size() == 1)
        {
            return 1;
        }
        while (s[r] == ' ')
        {
            r--;
        }
        while (s[r] != ' ' || s[r] == *s.begin())
        {
            ctr++;
            r--;
        }

        return ctr;
    }
};