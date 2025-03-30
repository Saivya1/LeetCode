#include <iostream>
#include <stack>
#include <unordered_map>

using namespace std;

int main()
{
    stack<char> st;
    unordered_map<char, char> pair = {
        {')', '('},
        {']', '['},
        {'}', '{'},

    };

    string s = "({[()]})";

    for (char b : s)
    {
        if (b == '[' || b == '{' || b == '(')
        {
            st.push(b);
        }
        else
        {
            if (st.top() == pair[b])
            {
                st.pop();
            }
            else
            {
                cout << "Invalid";
                exit(1);
            }
        }
    }
    cout << "valid";
}