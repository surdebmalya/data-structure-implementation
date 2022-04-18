// Question of IISC MTech admission 2022

#include <iostream>
#include <unordered_map>
using namespace std;

int dp(string str, int start, int end, auto &lookup) {
    if (start <= end) {
        string key = to_string(start) + "|" + to_string(end);
        if (lookup.find(key) == lookup.end()) {
            if (str[start] == str[end]) {
                lookup[key] = dp(str, start + 1, end - 1, lookup);
            } else {
                lookup[key] = 1 + min(dp(str, start + 1, end, lookup), dp(str, start, end - 1, lookup));
            }
            return lookup[key];
        } else {
            return lookup[key];
        }
    } else {
        return 0;
    }
}

int recursion(string str, int start, int end) {
    if (start <= end) {
        if (str[start] == str[end]) {
            return recursion(str, start + 1, end - 1);
        } else {
            return 1 + min(recursion(str, start, end - 1), recursion(str, start + 1, end));
        }
    } else {
        return 0;
    }
}

int main() {
    // Input: PIISBCCSQII
    // Answer: 3 => remove P, B, Q => IISCCSII
    string str;
    cin >> str;
    int size = str.size();

    cout << recursion(str, 0, size - 1) << endl;

    unordered_map<string, int> lookup;
    cout << dp(str, 0, size - 1, lookup) << endl;

    return 0;
}