// https://leetcode.com/problems/intersection-of-two-linked-lists/

// Easy

class Solution {
    int findLength(ListNode *head) {
        int length = 1;
        while (head->next != NULL) {
            length++;
            head = head->next;
        }
        return length;
    }

public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int length1 = findLength(headA);
        int length2 = findLength(headB);
        int diff = length1 - length2;
        if (diff > 0) {
            while (diff) {
                headA = headA->next;
                diff--;
            }
        } else if (diff < 0) {
            int diffNegative = -diff;
            while (diffNegative) {
                headB = headB->next;
                diffNegative--;
            }
        }

        // find intersection
        while (headA != NULL) {
            if (headA == headB) {
                return headA;
            }
            headA = headA->next;
            headB = headB->next;
        }
        return NULL;
    }
};