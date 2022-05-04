// https://leetcode.com/problems/remove-linked-list-elements/

// Easy

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
    ListNode *removeElements(ListNode *head, int val) {
        if (head == NULL) {
            return NULL;
        } else if (head->val != val) {
            head->next = removeElements(head->next, val);
            return head;
        } else {
            return removeElements(head->next, val);
        }
    }
};