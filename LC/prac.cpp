/*Example 1:

Input: strs = ["eat","tea","tan","ate","nat","bat"]

Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

Explanation:

    There is no string in strs that can be rearranged to form "bat".
    The strings "nat" and "tan" are anagrams as they can be rearranged to form each other.
    The strings "ate", "eat", and "tea" are anagrams as they can be rearranged to form each other.

Example 2:

Input: strs = [""]

Output: [[""]]

Example 3:

Input: strs = ["a"]

Output: [["a"]]
*/
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<string>> grpana(vector<string> strs)
    {
        string copy;
        unordered_map<string, vector<string>> um;
        vector<vector<string>> res;
        for (int i = 0; i < strs.size(); i++)
        {
            copy = strs[i];
            sort(strs[i].begin(), strs[i].end());
            um[strs[i]].push_back(copy);
        }
        for (const auto &it : um)
        {
            res.push_back(it.second);
        }

        return res;
    }
};

int main()
{
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};

    Solution s1;
    vector<vector<string>> res;
    res = s1.grpana(strs);

    for (const auto &innerVec : res)
    {
        for (const auto &str : innerVec)
        {
            cout << str << " ";
        }
        cout << endl;
    }
}