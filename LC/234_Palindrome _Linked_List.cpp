/* Given the head of a singly linked list, return true if it is a
palindrome
 or false otherwise.



Example 1:


Input: head = [1,2,2,1]
Output: true
Example 2:


Input: head = [1,2]
Output: false */

#include <iostream>
#include "LinkedList.h"
#include <vector>
#include <algorithm>

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
    bool isPalindrome(ListNode *head)
    {
        if (head == nullptr)
        {
            return false;
        }

        ListNode *temp = head;
        vector<int> nums;

        while (temp != nullptr)
        {
            nums.push_back(temp->val);
            temp = temp->next;
        }

        vector<int> nums_rev(nums.size());
        reverse_copy(nums.begin(), nums.end(), nums_rev.begin());

        return (nums == nums_rev);
    }
};