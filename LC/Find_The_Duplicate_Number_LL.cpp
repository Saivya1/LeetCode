

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int findDuplicate(ListNode* nums) {
        ListNode *curr = nums;
        unordered_set<ListNode*> us;

        if(!nums){
            return -1;
        }
        while(curr){
            if(us.find(curr) == us.end()){
            us.insert(curr);
            }
            else{
                return curr->val;
            }
            curr=curr->next;


        }    
        return -1;  
    }
};