/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* curr = head;

        unordered_map<ListNode*,int> um;



        while(curr != nullptr){

            if(um[curr] != 0){
                return true;
            }

            um[curr]++;
            curr=curr->next;

        }

        return false;
    }
};