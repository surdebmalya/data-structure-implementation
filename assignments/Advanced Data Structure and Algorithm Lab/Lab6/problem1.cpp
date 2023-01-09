class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        int zeros=0, ones=0;
        Node* curr = head;
        while(curr) {
            if(curr->data==0) zeros++;
            else if(curr->data==1) ones++;
            curr=curr->next;
        }
        curr=head;
        while(curr) {
            if(zeros) {
                curr->data=0;
                zeros--;
            }
            else if(ones) {
                curr->data=1;
                ones--;
            }
            else {
                curr->data=2;
            }
            curr = curr->next;
        }
        return head;
    }
};