/*
Assuming the numbers are ranging from 0 to 9 and integers only
*/
#include <cmath>
#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Stack {
    vector<char> stack;
    int size = 0;

public:
    bool isEmpty() {
        return (size == 0);
    }

    void push(char value) {
        stack.push_back(value);
        size++;
    }

    char pop() {
        char ele = stack[stack.size() - 1];
        stack.pop_back();
        size--;
        return ele;
    }
};

string infix_to_postfix(string infix) {
    string result = "";
    unordered_set <char> numbers = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    unordered_set <char> operatos = {'+', '-', '*', '/'};
    Stack stack;
    auto it = infix.begin();
    while (it != infix.end()) {
        if (*it=='(') {
            stack.push(*it);
        }
        else if(numbers.find(*it)!=numbers.end()) {
            result += *it;
        }
        else if (operatos.find(*it)!=operatos.end()) {
            stack.push(*it);
        }
        else {
            // only ')' encountered
            char op = stack.pop();
            while (op != '(') {
                result += op;
                op = stack.pop();
            }
        }
        it++;
    }
    return result;
}

void print_str(string str) {
    auto it = str.begin();
    while (it != str.end()) {
        cout << *it << " ";
        it++;
    }
    cout << endl;
}

int main() {
    // string str = "(2+3)"; // no spaces involved
    string str = "(((2+3)*(4/5))-6)";
    cout << "Infix Expression: ";
    print_str(str);

    string postfix = infix_to_postfix(str);
    cout << "Postfix Expression: ";
    print_str(postfix);

    return 0;
}