#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

string result = "";

void remove_duplicates(string str, int size, int index, char prev_ele) {
    if (index <= size - 1) {
        if (prev_ele == str[index]) {
            remove_duplicates(str, size, index + 1, prev_ele);
        } else {
            if (prev_ele != ' ') {
                result += prev_ele;
            }
            remove_duplicates(str, size, index + 1, str[index]);
        }
    } else if (index == size) {
        if (prev_ele != ' ') {
            result += prev_ele;
        }
        return;
    }
}

int main() {
    string str;
    cin >> str;
    remove_duplicates(str, str.size(), 0, ' ');
    cout << result;

    return 0;
}