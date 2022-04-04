/*
https://leetcode.com/problems/swapping-nodes-in-a-linked-list/

Medium
*/

/*
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
    ListNode* swapNodes(ListNode* head, int k) {
        int count = 1;
        ListNode* fast = head;
        while(count!=k) {
            fast = fast->next;
            count += 1;
        }
        ListNode* temp = fast;
        ListNode* slow = head;
        while(temp->next) {
            temp = temp->next;
            slow = slow->next;
        }
        int temp_val = slow->val;
        slow->val = fast->val;
        fast->val = temp_val;
        
        return head;
    }
};