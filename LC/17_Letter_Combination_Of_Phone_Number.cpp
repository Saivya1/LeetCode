/*Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.



Example 1:

Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]

Example 2:

Input: digits = ""
Output: []

Example 3:

Input: digits = "2"
Output: ["a","b","c"]
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    const vector<string> pad = {
        "", "", "abc", "def", "ghi", "jkl",
        "mno", "pqrs", "tuv", "wxyz"};

    vector<string> res;
    string cur = "";

    vector<string> letterCombinations(string digits)
    {
        if (digits.empty())
            return {};

        dfs(digits, 0);
        return res;
    }

private:
    void dfs(const string &digits, int idx)
    {
        if (idx == digits.size())
        {
            res.push_back(cur);
            return;
        }

        string letters = pad[digits[idx] - '0'];
        for (char c : letters)
        {
            cur.push_back(c);
            dfs(digits, idx + 1);
            cur.pop_back();
        }
    }
};
