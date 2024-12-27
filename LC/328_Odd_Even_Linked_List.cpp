/* Given the head of a singly linked list, group all the nodes with odd indices together followed by the nodes with even indices, and return the reordered list.

The first node is considered odd, and the second node is even, and so on.

Note that the relative order inside both the even and odd groups should remain as it was in the input.

You must solve the problem in O(1) extra space complexity and O(n) time complexity.



Example 1:


Input: head = [1,2,3,4,5]
Output: [1,3,5,2,4]
Example 2:


Input: head = [2,1,3,5,6,4,7]
Output: [2,3,6,7,1,5,4] */

#include <iostream>
#include <vector>
#include "LinkedList.h"

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
class Solution
{
public:
    ListNode *oddEvenList(ListNode *head)
    {
        if (!head || !head->next)
            return head; // Check for empty or single node list

        ListNode *odd = head;
        ListNode *even = head->next;
        ListNode *evenHead = even; // Save the start of the even list

        while (even && even->next)
        {
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }

        odd->next = evenHead; // Attach even list at the end of odd list

        return head;
    }
};

int main()
{
    ListNode *head = nullptr;
    LL l;

    l.insertatend(1, head);
    l.insertatend(2, head);
    l.insertatend(3, head);
    l.insertatend(4, head);
    l.insertatend(5, head);

    l.display(head);
    cout << "The answer : " << endl;

    Solution s;

    ListNode *newHead = s.oddEvenList(head);
    l.display(newHead);
}
