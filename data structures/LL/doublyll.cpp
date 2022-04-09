#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
    struct Node * prev;
    int data;
    struct Node * next;
};

class DLL {
    struct Node * head = NULL;
    struct Node * tail = NULL;
    int size = 0;
public:
    // DLL() {
    //     head = NULL;
    // }
    bool isEmpty() {
        return size==0;
    }

    int length() {
        return size;
    }

    void add_end(int value) {
        struct Node * temp = new struct Node();
        temp->prev = NULL;
        temp->data = value;
        temp->next = NULL;
        if (size!=0) {
            tail->next = temp;
            temp->prev = tail;
            size++;
            tail = temp;
        }
        else {
            head = temp;
            tail = temp;
            size++;
        }
    }

    void add_front(int value) {
        struct Node * temp = new struct Node();
        temp->prev = NULL;
        temp->data = value;
        temp->next = NULL;
        if (size!=0) {
            temp->next = head;
            head->prev = temp;
            size++;
            head = temp;
        }
        else {
            head = temp;
            tail = temp;
            size++;
        }
    }

    void del_end() {
        if (size!=0) {
            struct Node * temp = tail;
            tail = tail-> prev;
            tail->next = NULL;
            free(temp);
            size--;
        }
        else {
            return;
        }
    }

    void del_front() {
        if (size!=0) {
            struct Node * temp = head;
            head = head->next;
            head->prev = NULL;
            free(temp);
            size--;
        }
        else {
            return;
        }
    }

    void print_dll() {
        struct Node * temp = head;
        while (temp!=NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    DLL d;
    d.add_end(1);
    d.add_end(2);
    d.add_end(3);
    d.add_end(4);
    d.add_end(5);

    d.print_dll();

    d.add_front(-1);
    d.add_front(-2);
    d.add_front(-3);
    d.add_front(-4);
    d.add_front(-5);

    d.print_dll();

    d.del_end();

    d.print_dll();

    d.del_front();

    d.print_dll();

    cout << "Size of the Doubly Linked List: " << d.length() << endl;

    return 0;
}