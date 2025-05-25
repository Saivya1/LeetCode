/* Given the head of a linked list, remove the nth node from the end of the list and return its head.



Example 1:


Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]
Example 2:

Input: head = [1], n = 1
Output: []
Example 3:

Input: head = [1,2], n = 1
Output: [1] */

#include <iostream>
#include "LinkedList.h"

using namespace std;

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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {

        if (!head)
            return head;
        ListNode *curr = head;
        int ctr = 0;

        while (curr)
        {
            curr = curr->next;
            ctr++;
        }

        int offset = ctr - n;

        if (offset == 0)
        {
            return head->next;
        }

        curr = head;

        for (int i = 0; i < offset - 1; i++)
        {
            curr = curr->next;
        }

        ListNode *temp = curr->next->next;
        delete curr->next;
        curr->next = temp;

        return head;
    }
};

int main()
{
    Solution s;

    LL l;
    ListNode *head = nullptr;

    l.insertatend(1, head);
    l.insertatend(2, head);
    l.insertatend(3, head);
    l.insertatend(4, head);
    l.insertatend(5, head);

    l.display(head);

    head = s.removeNthFromEnd(head, 2);

    l.display(head);
}