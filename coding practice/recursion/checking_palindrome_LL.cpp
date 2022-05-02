// https://leetcode.com/problems/palindrome-linked-list/

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
    pair<int, struct ListNode *> find_middle(struct ListNode *head) {
        struct ListNode *slow = head;
        struct ListNode *fast = head->next;
        bool flag = true;
        int count = 2;
        while (fast->next != NULL) {
            if (flag) {
                slow = slow->next;
                flag = false;
            } else {
                flag = true;
            }
            fast = fast->next;
            count++;
        }
        return make_pair(count, slow);
    }

    bool checking_palindrome(struct ListNode *right, struct ListNode *left) {
        while (right != NULL) {
            if (right->val == left->val) {
                right = right->next;
                left = left->next;
            } else {
                return false;
            }
        }
        return true;
    }

public:
    bool isPalindrome(ListNode *head) {
        if (head == NULL or head->next == NULL) {
            return true;
        }
        auto result = find_middle(head);
        int length = result.first;
        struct ListNode *middle = result.second;

        struct ListNode *prev = NULL;
        struct ListNode *curr = head;
        struct ListNode *nxt = curr->next;
        while (curr != middle) {
            curr->next = prev;
            prev = curr;
            curr = nxt;
            nxt = nxt->next;
        }
        curr->next = prev;

        struct ListNode *r = NULL;
        struct ListNode *l = NULL;
        if ((length % 2) != 0) {
            r = prev;
            l = nxt;
        } else {
            r = curr;
            l = nxt;
        }

        return checking_palindrome(r, l);
    }
};