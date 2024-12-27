/* Given an integer x, return true if x is a
palindrome
, and false otherwise.



Example 1:

Input: x = 121
Output: true
Explanation: 121 reads as 121 from left to right and from right to left.
Example 2:

Input: x = -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
Example 3:

Input: x = 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome. */

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
    // bool isPalindrome(int x)
    // {
    //     int sum = 0;
    //     int dig;
    //     int copy = x;
    //     while (x > 0)
    //     {
    //         dig = x % 10;
    //         x = x / 10;                        // Gives Overflow for long integer values
    //         sum = sum * 10 + dig;
    //     }
    //     cout << sum;
    //     return (copy == sum);
    // }
    bool isPalindrome(int x)
    {
        string str_x = to_string(x);
        string copy_str_x = to_string(x);
        reverse(str_x.begin(), str_x.end());

        return (str_x == copy_str_x);
    }
};

int main()
{
    int x = 121;
    Solution s;

    cout << s.isPalindrome(x);
}
