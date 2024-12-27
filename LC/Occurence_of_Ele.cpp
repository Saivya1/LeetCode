#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

class Solution {
public:
     

    bool inVec(vector<int> &nums,int element){
        auto it=find(nums.begin(),nums.end(),element);

        if(it!=nums.end()){
            return true;
        }
        else{
            return false;
        }
    }

    void occurrence(vector<int> &nums){
        int size = nums.size();
        map<int,int> mp;
        vector<int> nondupli;

        for(int x : nums){
            if(!inVec(nondupli,x)){
                nondupli.push_back(x);
            }
        }

        for(int y : nondupli){
            mp[y]=0;
        }

        auto it = mp.begin();

        for(int u : nums){
            mp[u]++;
        }

        while(it!=mp.end()){
            cout << "Key : " << it->first << endl;
            cout << "Value : " << it->second << endl;
            ++it;
        }

    }
};

int main() {
    vector<int> nums{1, 0, 1, 0, 2, 2, 3, 2};
    Solution s;

    s.occurrence(nums);
   
}