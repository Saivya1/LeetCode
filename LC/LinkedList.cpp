#ifndef LinkedList
#define LinkedList

#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x)
    {
        val = x;
        next = nullptr;
    }
};

class LL
{
public:
    void insertatbeg(int value, ListNode *&head)
    {
        ListNode *newnode = new ListNode(value);
        newnode->next = head;
        head = newnode;
    }

    void display(ListNode *head)
    {
        ListNode *temp = head;

        while (temp != nullptr)
        {
            cout << temp->val << " ";
            temp = temp->next;
        }
    }

    void insertatend(int val, ListNode *&head)
    {
        ListNode *newnode = new ListNode(val);
        newnode->next = nullptr;
        if (head == nullptr)
        {
            head = newnode;
        }
        else
        {
            ListNode *temp = head;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = newnode;
        }
    }

    void deleteNodeWithValue(int value, ListNode *&head)
    {
        if (head == nullptr)
        {
            return;
        }

        if (head->val == value)
        {
            head = head->next;
        }

        ListNode *prev = head;
        ListNode *curr = head->next;

        while (curr != nullptr)
        {
            if (curr->val == value)
            {
                prev->next = curr->next;
                delete curr;
                return;
            }
            prev = curr;
            curr = curr->next;
        }
    }
};

#endif