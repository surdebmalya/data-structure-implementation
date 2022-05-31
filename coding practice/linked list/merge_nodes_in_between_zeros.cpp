// https://leetcode.com/problems/merge-nodes-in-between-zeros/

// Medium

class Solution {
public:
    ListNode *mergeNodes(ListNode *head) {
        int currVal = 0;
        ListNode *curr = head;
        ListNode *prev = NULL;
        while (curr != NULL) {
            if (curr->val == 0) {
                if (prev == NULL)
                    prev = curr;
                else {
                    prev->next = curr;
                    prev = prev->next;
                }
                curr->val = currVal;
                currVal = 0;
            } else {
                currVal += curr->val;
            }
            curr = curr->next;
        }
        return head->next;
    }
};