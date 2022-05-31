// https://leetcode.com/problems/merge-in-between-linked-lists/

// Medium

class Solution {
public:
    ListNode *mergeInBetween(ListNode *list1, int a, int b, ListNode *list2) {
        int diff = b - a + 1;
        ListNode *head = list1;
        while (a - 1) {
            head = head->next;
            a--;
        }
        ListNode *remove = head->next;
        head->next = list2;
        while (head->next != NULL)
            head = head->next;
        while (diff) {
            remove = remove->next;
            diff--;
        }
        head->next = remove;
        return list1;
    }
};