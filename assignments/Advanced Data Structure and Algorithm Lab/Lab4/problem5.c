#include <stdio.h>
#include <stdlib.h>

int carry=1;

struct Node {
    int val;
    struct Node* next;
};

struct Node* newNode(int v) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->val = v;
    temp->next = NULL;
    return temp;
}

void print(struct Node* head) {
    while(head!=NULL) {
        printf("%d", head->val);
        head=head->next;
    }
    printf("\n");
}

struct Node* addOne(struct Node* head) {
    if(head==NULL) return NULL;
    head->next = addOne(head->next);
    int temp = head->val + carry;
    head->val = temp%10;
    carry = temp/10;
    return head;
}

int main() {
    struct Node* head = newNode(9);
    head->next = newNode(9);
    head->next->next = newNode(9);
    print(head);
    head = addOne(head);
    if(carry!=0) {
        struct Node* newHead = newNode(carry);
        newHead->next = head;
        head = newHead;
    }
    print(head);

    return 0;
}
