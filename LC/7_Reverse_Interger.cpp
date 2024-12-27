/* Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

Assume the environment does not allow you to store 64-bit integers (signed or unsigned).



Example 1:

Input: x = 123
Output: 321
Example 2:

Input: x = -123
Output: -321
Example 3:

Input: x = 120
Output: 21 */

#include <iostream>
#include <algorithm>
#include <string>

// cant use using namespace std becauase the name of user defined function is reverse and the the predefined function is also called reverse

class Solution
{
public:
    int reverse(int x)
    {
        bool neg = x < 0;

        std::string str_x = std::to_string(std::abs(x));
        std::reverse(str_x.begin(), str_x.end());
        if (str_x.length() > 10 || (str_x.length() == 10 && str_x > "2147483647")) // Check for overflow
        {
            return 0;
        }
        long long reversed_num = std::stoll(str_x);
        if (neg)
        {
            reversed_num = -reversed_num;
        }

        return static_cast<int>(reversed_num);
    }
};
int main()
{
    int x = -123;
    int res;

    Solution s;

    res = s.reverse(x);

    std::cout << res;
}