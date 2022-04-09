#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
    Node * next;
    int data;
};

class List {
    Node * head;
public:
    List() {
        head = NULL;
    }
    void insert_end(int value) {
        Node * temp = new Node();
        temp->data = value;
        temp->next = NULL;
        if (head==NULL) {
            head = temp;
        }
        else {
            Node * temp_head = head;
            while (temp_head->next != NULL) {
                temp_head = temp_head->next;
            }
            temp_head->next = temp;
        }
    }
    void print_LL() {
        Node * temp = head;
        while (temp!=NULL) {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout <<"NULL"<< endl;
    }
    
    void insert_front(int value) {
        Node * temp = new Node();
        temp->data = value;
        temp->next = NULL;
        if (head==NULL) {
            head=temp;
        }
        else {
            temp->next = head;
            head=temp;
        }
    }

    int size() {
        Node * temp = head;
        int count = 0;
        while (temp!=NULL) {
            count++;
            temp = temp->next;
        }
        return count;
    }
};

int main() {
    List ll;
    ll.insert_end(1);
    ll.insert_end(2);
    ll.insert_end(3);
    ll.insert_end(4);
    ll.insert_end(5);

    ll.print_LL();

    ll.insert_front(6);

    ll.print_LL();

    cout << "Size of the Linked List: " << ll.size() << endl;

    return 0;
}