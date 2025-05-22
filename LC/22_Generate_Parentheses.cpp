/*Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.



Example 1:

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]

Example 2:

Input: n = 1
Output: ["()"]
*/

#include <iostream>
#include <vector>

using namespace std;
class Solution
{
public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> res;
        dfs(0, 0, "", n, res);
        return res;
    }

private:
    void dfs(int openP, int closeP, string s, int n, vector<string> &res)
    {
        if (openP == closeP && openP + closeP == n * 2)
        {
            res.push_back(s);
            return;
        }

        if (openP < n)
        {
            dfs(openP + 1, closeP, s + "(", n, res);
        }

        if (closeP < openP)
        {
            dfs(openP, closeP + 1, s + ")", n, res);
        }
    }
};