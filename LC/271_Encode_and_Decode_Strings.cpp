/* Design an algorithm to encode a list of strings to a single string. The encoded string is then decoded back to the original list of strings.

Please implement encode and decode

Example 1:

Input: ["neet","code","love","you"]

Output:["neet","code","love","you"]
Example 2:

Input: ["we","say",":","yes"]

Output: ["we","say",":","yes"] */

#include <iostream>
#include <vector>   
#include <string>

using namespace std;

class Solution {
public:

    string encode(vector<string>& strs) {
        string res;
        for(string s : strs){
            res += to_string(s.length())+"#"+s;
        }
        return res;
    }

    vector<string> decode(string s) {
        vector<string> res;
        int i = 0;
        while (i < s.length()) {
            int j = s.find('#', i);
            int length = stoi(s.substr(i, j - i));
            i = j + 1;
            string str = s.substr(i, length);
            res.push_back(str);
            i += length;
        }
        return res;
    }
};

int main(){
    vector<string> strs{"neet","code","love","you"};
    vector<string> decoded;
    Solution s;

    string res = s.encode(strs);
    cout << res <<endl;

    decoded = s.decode(res);

    for(string x : decoded){
        cout << x <<" ";
    }



}
