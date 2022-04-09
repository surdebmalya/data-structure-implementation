#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;

class Deque {
    list <int> deque;
public:
    void insert_end(int value) {
        deque.push_back(value);
    }

    void insert_front(int value) {
        deque.push_front(value);
    }

    bool isEmpty() {
        return deque.size()==0;
    } 

    int pop_back() {
        if (isEmpty()) {
            return -1;
        }
        else {
            int ele = deque.back();
            deque.pop_back();
            return ele;
        }
    }

    int pop_front() {
        if (isEmpty()) {
            return -1;
        }
        else {
            int ele = deque.front();
            deque.pop_front();
            return ele;
        }
    }

    void remove_index_from_front(int index) {
        if (index < deque.size()) {
            auto it = deque.begin();
            int count = 0;
            while (count!=index) {
                it++;
                count++;
            }
            deque.erase(it);
        }
        else {
            return;
        }
    }

    void remove_index_from_end(int index) {
        if (index < deque.size()) {
            int from_front_index = deque.size() - index - 1;
            remove_index_from_front(from_front_index);
        }
        else {
            return;
        }
    }

    void print_deque() {
        auto it = deque.begin();
        while (it!=deque.end()) {
            cout << *it << " ";
            it++;
        }
        cout << endl;
    }
};

int main() {
    Deque deque;
    deque.insert_end(1);
    deque.insert_end(2);
    deque.insert_end(3);
    deque.insert_end(4);
    deque.insert_front(-1);
    deque.insert_front(-2);
    deque.insert_front(-3);
    deque.insert_front(-4);

    deque.print_deque();

    cout << "Popped back element: " << deque.pop_back() << endl;

    deque.print_deque();

    cout << "Popped front element: " << deque.pop_front() << endl;

    deque.print_deque();

    deque.remove_index_from_front(3);

    deque.print_deque();

    deque.remove_index_from_end(3);

    deque.print_deque();

    return 0;
}