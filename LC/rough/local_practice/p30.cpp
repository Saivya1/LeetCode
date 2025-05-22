#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<string> generateParen(int n)
    {
        vector<string> res;
        dfs(0, 0, "", n, res);
        return res;
    }

private:
    void dfs(int num_op, int num_close, string s, int n, vector<string> &res)
    {
        if (num_op == num_close && num_op + num_close == 2 * n)
        {
            res.push_back(s);
            return;
        }
        if (num_op < n)
        {
            dfs(num_op + 1, num_close, s + "(", n, res);
        }
        if (num_close < num_op)
        {
            dfs(num_op, num_close + 1, s + ")", n, res);
        }
    }
};