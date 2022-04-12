/*
Qn2: given an string (ex: XxYYyYzzabXCccc),
covert it to this "x2y4z2abxc4"
(characters are case insensitive, and you have to insert the
number of time a character occur consecutively.. >1 )
*/
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

string lower_case(string str) {
    int A = 'A', Z = 'Z', a = 'a';
    string result = "";
    auto it = str.begin();
    while (it != str.end()) {
        if (*it >= A and *it <= Z) {
            char temp = *it + (a - A);
            result += temp;
        } else {
            result += *it;
        }
        it++;
    }
    return result;
}

string convert(string str_mixture) {
    string str = lower_case(str_mixture);
    string result = "";
    char curr = '-';
    int count = 0;
    auto it = str.begin();
    while (it != str.end()) {
        if (curr == '-') {
            curr = *it;
            count++;
        } else if (curr != '-' and *it == curr) {
            count++;
        } else {
            if (count > 1) {
                result = result + curr + char(count);
            } else {
                result = result + curr;
            }
            curr = *it;
            count = 1;
        }

        it++;
    }
    if (count > 1) {
        result = result + curr + char(count);
    } else {
        result = result + curr;
    }
    return result;
}

int main() {
    string str = "x2y4z2abxc4";
    cout << "Converted String Will Be: " << convert(str) << endl;

    return 0;
}