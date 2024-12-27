/* Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.


Example 1:

Input: s = "()"
Output: true
Example 2:

Input: s = "()[]{}"
Output: true
Example 3:

Input: s = "(]"
Output: false */

#include <iostream>
#include <string>
#include <unordered_map>
#include <stack>

using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> st;
        unordered_map<char, char> matchingBrackets = {
            {')', '('},
            {']', '['},
            {'}', '{'}};

        for (char ch : s)
        {
            // If it's a closing bracket
            if (matchingBrackets.find(ch) != matchingBrackets.end())
            {
                // Check if the stack is empty or the top of the stack does not match
                if (st.empty() || st.top() != matchingBrackets[ch])
                {
                    return false;
                }
                st.pop(); // Pop the matching opening bracket from the stack
            }
            else
            {
                // It's an opening bracket
                st.push(ch);
            }
        }

        // If the stack is empty, all opening brackets were matched
        return st.empty();
    }
};

int main()
{
    string s = "()[]{}";

    Solution s1;

    cout << s1.isValid(s);
}