/* Write a function that reverses a string. The input string is given as an array of characters s.

You must do this by modifying the input array in-place with O(1) extra memory.



Example 1:

Input: s = ["h","e","l","l","o"]
Output: ["o","l","l","e","h"]
Example 2:

Input: s = ["H","a","n","n","a","h"]
Output: ["h","a","n","n","a","H"] */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    void reverseString(vector<char> &s)
    {
        int l = 0;
        int r = s.size() - 1;

        while (l < r)
        {
            swap(s[l], s[r]);
            l++;
            r--;
        }
    }
};

int main()
{
    vector<char> s{'H', 'e', 'l', 'l', 'o'};

    Solution s1;

    s1.reverseString(s);

    for (char ch : s)
    {
        cout << ch << " ";
    }
}