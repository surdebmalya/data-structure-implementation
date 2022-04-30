// https://leetcode.com/problems/reverse-linked-list/

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
private:
    ListNode *reverse(ListNode *prev, ListNode *curr) {
        if (curr != NULL and curr->next != NULL) {
            struct ListNode *temp = curr->next;
            curr->next = prev;
            return reverse(curr, temp);
        } else {
            if (curr == NULL) {
                return NULL;
            } else {
                curr->next = prev;
                return curr;
            }
        }
    }

public:
    ListNode *reverseList(ListNode *head) {
        return reverse(NULL, head);
    }
};