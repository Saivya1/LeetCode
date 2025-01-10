class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        if (!head) return head;
        ListNode* curr = head;
        int ctr = 0;

        while (curr) {
            curr = curr->next;
            ctr++;
        }

        int offset = ctr - n;

        if (offset == 0) {
            return head->next;
        }

        curr = head;

        for (int i = 0; i < offset-1; i++) {
            curr = curr->next;
        }

        ListNode* temp = curr->next->next;
        delete curr->next;
        curr->next = temp;

        return head;
    }
};
