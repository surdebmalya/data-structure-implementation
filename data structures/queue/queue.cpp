#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;

class Queue {
    list <int> queue;
public:
    bool isEmpty() {
        return queue.size() == 0;
    }

    void enqueue(int value) {
        queue.push_back(value);
    }

    int dequeue() {
        if (isEmpty()) {
            return -1;
        }
        else {
            int ele = queue.front();
            queue.pop_front();
            return ele;
        }
    }

    void print_queue() {
        auto it = queue.begin();
        while (it != queue.end()) {
            cout << *it << " ";
            it++;
        }
        cout << endl;
    }
};

int main() {
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);

    q.print_queue();
    
    cout << "Dequeued Element: " << q.dequeue() << endl;

    q.print_queue();

    return 0;
}