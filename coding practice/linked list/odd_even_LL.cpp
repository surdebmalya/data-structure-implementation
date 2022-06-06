// https://leetcode.com/problems/odd-even-linked-list/

// Medium

class Solution {
public:
    ListNode *oddEvenList(ListNode *head) {
        // base case
        if (head == NULL or head->next == NULL)
            return head;

        ListNode *odd = head, *even = head->next, *evenStart = even, *track = head;
        int count = 1;
        while (track != NULL) {
            if (count > 2) {
                if (count % 2) {
                    // odd
                    odd->next = track;
                    odd = odd->next;
                } else {
                    // even
                    even->next = track;
                    even = even->next;
                }
            }
            track = track->next;
            count++;
        }
        odd->next = evenStart;
        even->next = NULL;
        return head;
    }
};