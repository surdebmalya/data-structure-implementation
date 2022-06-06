// https://leetcode.com/problems/linked-list-cycle-ii/

// Medium

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL or head->next == NULL)
            return NULL;
        if (head->next == head)
            return head;

        // now the linked list has atleast 2 nodes
        ListNode *slow = head, *fast = head->next;
        while (fast != NULL and fast->next != NULL) {
            if (slow != fast) {
                slow = slow->next;
                fast = fast->next->next;
            } else
                break;
        }
        if (fast == NULL or fast->next == NULL)
            return NULL;
        // we have the intersection of two linked list
        fast = NULL;
        while (fast != slow) {
            if (fast == NULL)
                fast = head;
            else
                fast = fast->next;
            slow = slow->next;
        }
        return fast;
    }
};