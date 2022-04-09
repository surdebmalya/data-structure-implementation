#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Stack {
private:
    vector<int> stack;

public:
    void push(int value) {
        stack.push_back(value);
    }

    int pop() {
        if (stack.size()==0) {
            return -1;
        }

        int ele = stack[stack.size()-1];
        stack.pop_back();
        return ele;
    }

    bool isEmpty() {
        return stack.size()==0;
    }

    int peak() {
        if (stack.size()==0) {
            return -1;
        }
        return stack[stack.size()-1];
    }
};

int main() {

    Stack stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);

    cout << stack.peak() << endl;
    cout << stack.pop() << endl;
    stack.push(6);
    cout << stack.peak() << endl;

    return 0;
}