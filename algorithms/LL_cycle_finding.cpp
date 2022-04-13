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
    temp_node->next = NULL;
    temp_node->data = value;
    return temp_node;
};

int find_cycle(struct Node *head) {
    struct Node *slow = head;
    struct Node *fast = head->next;
    while (fast->next != NULL and fast->next->next != NULL) {
        if (slow == fast) {
            return 1;
        } else {
            slow = slow->next;
            fast = fast->next->next;
        }
    }
    return 0;
}

int main() {
    // example 1
    struct Node *head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(5);
    head->next->next->next->next->next = head->next->next;
    cout << "For Example 1: ";
    if (find_cycle(head)) {
        cout << "There is cycle" << endl;
    } else {
        cout << "There is no cycle" << endl;
    }

    // example 2
    struct Node *head2 = newNode(1);
    head2->next = newNode(2);
    head2->next->next = newNode(3);
    head2->next->next->next = newNode(4);
    head2->next->next->next->next = newNode(5);
    cout << "For Example 2: ";
    if (find_cycle(head2)) {
        cout << "There is cycle" << endl;
    } else {
        cout << "There is no cycle" << endl;
    }

    return 0;
}