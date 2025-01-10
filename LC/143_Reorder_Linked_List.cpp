/*You are given the head of a singly linked-list. The list can be represented as:

L0 → L1 → … → Ln - 1 → Ln

Reorder the list to be on the following form:

L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …

You may not modify the values in the list's nodes. Only nodes themselves may be changed.

 

Example 1:

Input: head = [1,2,3,4]
Output: [1,4,2,3]

Example 2:

Input: head = [1,2,3,4,5]
Output: [1,5,2,4,3]
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {

        if (!head || !head->next || !head->next->next) return; // Base case for small lists
        
        // Step 1: Find the middle of the list
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Reverse the second half of the list
        ListNode* head2 = slow->next;
        slow->next = nullptr; // Break the list into two halves
        ListNode* prev = nullptr;
        ListNode* temp;

        while (head2) {
            temp = head2->next;
            head2->next = prev;
            prev = head2;
            head2 = temp;
        }

        // Step 3: Merge the two halves
        ListNode* l1 = head;
        ListNode* l2 = prev; // `prev` is the head of the reversed second half

        while (l2) {
            temp = l1->next;  // Save the next node in the first half
            l1->next = l2;    // Link the current node to the head of the second half
            l1 = l2;          // Move to the next node in the second half
            l2 = temp;        // Update `l2` to point to the saved node
        }
    }
};
