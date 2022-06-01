// https://leetcode.com/problems/reverse-linked-list-ii/

// Medium

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        int count=1;
        ListNode* curr=head;
        ListNode* prev=NULL;
        while(count!=left) {
            if(prev==NULL) 
                prev=head;
            else prev=prev->next;
            curr=curr->next;
            count++;
        }
        
        // reversing the designated area of the linked list
        ListNode* tail=curr;
        ListNode* prevRev=NULL;
        ListNode* nxt=curr->next;
        while(count!=right) {
            curr->next=prevRev;
            prevRev=curr;
            curr=nxt;
            nxt=nxt->next;
            count++;
        }
        curr->next=prevRev;
        
        if(prev!=NULL) 
            prev->next=curr;
        else 
            head=curr;
        if(nxt!=NULL)
            tail->next=nxt;
        return head;
    }
};