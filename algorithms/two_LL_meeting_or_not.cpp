#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

struct Node {
    struct Node *next;
    int data;
};

struct Node *newNode(int value) {
    struct Node *temp_node = new Node();
    temp_node->data = value;
    temp_node->next = NULL;
    return temp_node;
};

int finding_length(struct Node *root) {
    int length = 0;
    struct Node *temp = root;
    while (temp != NULL) {
        length++;
        temp = temp->next;
    }
    return length;
}

int whether_meets(struct Node *head1, struct Node *head2) {
    // returns 1, if meeting
    while (head1 != NULL) {
        if (head1 == head2) {
            return 1;
        } else {
            head1 = head1->next;
            head2 = head2->next;
        }
    }
    return 0;
}

int meet_or_not(struct Node *head1, struct Node *head2) {
    int length1 = finding_length(head1);
    int length2 = finding_length(head2);

    if (length1 > length2) {
        int count = (length1 - length2);
        while (count) {
            head1 = head1->next;
            count--;
        }
        if (whether_meets(head1, head2)) {
            return 1;
        } else {
            return 0;
        }
    } else {
        int count = (length2 - length1);
        while (count) {
            head2 = head2->next;
            count--;
        }
        if (whether_meets(head1, head2)) {
            return 1;
        } else {
            return 0;
        }
    }
}

int main() {
    // example 1
    struct Node *head1 = newNode(1);
    head1->next = newNode(2);
    head1->next->next = newNode(3);
    head1->next->next->next = newNode(4);
    head1->next->next->next->next = newNode(5);
    struct Node *head2 = newNode(3);
    head2->next = head1->next->next;
    cout << "For Example 1: ";
    if (meet_or_not(head1, head2)) {
        cout << "Linked Lists are meeting" << endl;
    } else {
        cout << "Linked Lists are not meeting" << endl;
    }

    // example 2
    struct Node *head3 = newNode(1);
    head3->next = newNode(2);
    head3->next->next = newNode(3);
    head3->next->next->next = newNode(4);
    head3->next->next->next->next = newNode(5);
    struct Node *head4 = newNode(3);
    head4->next = newNode(3);
    head4->next->next = newNode(4);
    head4->next->next->next = newNode(5);
    cout << "For Example 2: ";
    if (meet_or_not(head3, head4)) {
        cout << "Linked Lists are meeting" << endl;
    } else {
        cout << "Linked Lists are not meeting" << endl;
    }

    return 0;
}