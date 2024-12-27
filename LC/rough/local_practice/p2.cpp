#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        if (s.size() == 1 or s == "")
        {
            return false;
        }
        stack<char> st;
        unordered_map<char, char> um = {
            {'}', '{'},
            {')', '('},
            {']', '['}};

        for (char b : s)
        {
            if (b == '{' or b == '[' or b == '(')
            {
                st.push(b);
            }
            else
            {
                if (st.top() == um[b])
                {
                    st.pop();
                }
                else
                {
                    return false;
                }
            }
        }
        if (st.empty())
        {

            return true;
        }
        return false;
    }
};