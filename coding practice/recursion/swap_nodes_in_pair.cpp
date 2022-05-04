// https://leetcode.com/problems/swap-nodes-in-pairs/

// Medium

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
class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        if (head == NULL or head->next == NULL) {
            return head;
        }
        struct ListNode *slow = head;
        struct ListNode *fast = head->next;
        struct ListNode *t = fast->next;
        slow->next = t;
        fast->next = slow;
        slow->next = swapPairs(slow->next);
        return fast;
    }
};