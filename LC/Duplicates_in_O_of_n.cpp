/* Input: n=7 , array[]={1, 2, 3, 6, 3, 6, 1}
Output: 1, 3, 6
Explanation: The numbers 1 , 3 and 6 appears more than once in the array.

Input : n = 5 and array[] = {1, 2, 3, 4 ,3}
Output: 3
Explanation: The number 3 appears more than once in the array. */

#include <iostream>
#include <vector>
using namespace std;
int main(){
    vector<int> arr{1,2,3,6,3,6,1};
    vector<int> temp{0,0,0,0,0,0,0};

    for(int i=0;i<arr.size();i++){
        if(temp[arr[i]] == 0){
            temp[arr[i]]=1;
        }
        else{
            cout << arr[i] << endl;
        }
    }
}

/*Better Solution

class Solution {
public:
    bool containsDuplicate(std::vector<int>& nums) {
        std::unordered_set<int> seen;
        for (int num : nums) {
            if (seen.count(num)) {
                return true;
            }
            seen.insert(num);
        }
        return false;
    }
};

*/