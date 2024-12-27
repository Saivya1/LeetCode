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
        ListNode *tail = head;
        ListNode *temp = head;
        int num_nodes = 1;

        while (tail->next != nullptr)
        {
            num_nodes++;
            tail = tail->next;
        }

        int dist_from_start = num_nodes - n;

        if (dist_from_start == 0)
        {
            ListNode *new_head = head->next;
            delete head;
            return new_head;
        }

        while (dist_from_start > 1)
        {
            temp = temp->next;

            dist_from_start--;
        }

        ListNode *next_node = temp->next;
        temp->next = next_node->next;
        delete next_node;

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