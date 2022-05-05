// https://leetcode.com/problems/reorder-list/

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
    void reorderList(ListNode *head) {
        // finding middle
        if (head->next == NULL or head->next->next == NULL) {
            return;
        }
        struct ListNode *slow = head;
        struct ListNode *fast = head;
        while (fast->next != NULL and fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        if (fast->next != NULL and fast->next->next == NULL) {
            slow = slow->next;
        }
        struct ListNode *middle = slow;

        // reverse the rest of the list after the middle
        struct ListNode *prev = middle;
        struct ListNode *curr = middle->next;
        while (curr != NULL) {
            struct ListNode *temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        struct ListNode *tail = prev;
        middle->next = NULL;

        // build the connections
        while (tail != middle) {
            struct ListNode *next_head = head->next;
            struct ListNode *next_tail = tail->next;
            head->next = tail;
            tail->next = next_head;
            head = next_head;
            tail = next_tail;
        }

        return;
    }
};