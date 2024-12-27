#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        //["2","1","+","3","*"]
        vector<string> op = {"+", "-", "*", "/"};
        stack<int> st;
        for (string s : tokens)
        {
            if (find(op.begin(), op.end(), s) != op.end())
            {
                if (s == "+")
                {
                    int a = st.top();
                    st.pop();
                    int b = st.top();
                    st.pop();
                    st.push(a + b);
                }
                else if (s == "*")
                {
                    int a = st.top();
                    st.pop();
                    int b = st.top();
                    st.pop();
                    st.push(a * b);
                }
                else if (s == "-")
                {
                    int b = st.top();
                    st.pop();
                    int a = st.top();
                    st.pop();

                    st.push(a - b);
                }
                else if (s == "/")
                {
                    int b = st.top();
                    st.pop();
                    int a = st.top();
                    st.pop();
                    st.push(a / b);
                }
            }
            else
            {
                st.push(stoi(s));
            }
        }
        return (st.top());
    }
};