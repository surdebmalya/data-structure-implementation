// https://leetcode.com/problems/next-greater-node-in-linked-list/

// Medium

class Solution {
private:
    ListNode *reverseLL(ListNode *head) {
        if (head->next == NULL)
            return head;
        if (head->next->next == NULL) {
            ListNode *temp1 = head, *temp2 = head->next;
            temp2->next = temp1;
            temp1->next = NULL;
            return temp2;
        }
        ListNode *prev = NULL, *curr = head, *nxt = head->next;
        while (nxt != NULL) {
            curr->next = prev;
            prev = curr;
            curr = nxt;
            nxt = nxt->next;
        }
        curr->next = prev;
        return curr;
    }

public:
    vector<int> nextLargerNodes(ListNode *head) {
        // reverse the linked list
        head = reverseLL(head);

        // use stack to find next larger element
        vector<int> result;
        result.push_back(0);
        stack<int> s;
        s.push(head->val);
        head = head->next;
        while (head != NULL) {
            int currEle = head->val;
            while (!(s.empty()) and s.top() <= currEle) {
                s.pop();
            }
            if (s.empty())
                result.push_back(0);
            else
                result.push_back(s.top());
            s.push(currEle);
            head = head->next;
        }
        reverse(result.begin(), result.end());
        return result;
    }
};