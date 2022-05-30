// https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/

// Medium

class Solution {
public:
    int pairSum(ListNode* head) {
        stack<int> q;
        ListNode* slow=head;
        ListNode* fast=slow->next;
        q.push(slow->val);
        while(fast!=NULL and fast->next!=NULL) {
            slow=slow->next;
            q.push(slow->val);
            fast=fast->next->next;
        }
        slow=slow->next;
        int result = INT_MIN;
        while(slow!=NULL) {
            int temp = q.top()+slow->val;
            q.pop();
            slow=slow->next;
            result=max(result, temp);
        }
        return result;
    }
};