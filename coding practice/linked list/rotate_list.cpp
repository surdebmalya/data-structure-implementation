// https://leetcode.com/problems/rotate-list/

// Medium

class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        if (head == NULL or head->next == NULL or k == 0)
            return head;

        // finding total number of nodes
        int nodes = 0;
        ListNode *root = head;
        while (root != NULL) {
            nodes++;
            root = root->next;
        }

        // skiping the front desire nodes
        int pass = nodes - k % nodes;
        if (pass == nodes)
            return head; // rotated into the same position
        root = NULL;
        while (pass) {
            if (root == NULL)
                root = head;
            else
                root = root->next;
            pass--;
        }

        // adjusting the linked list
        ListNode *newRoot = root->next;
        root->next = NULL;
        root = newRoot;
        while (root->next != NULL)
            root = root->next;
        root->next = head;
        return newRoot;
    }
};