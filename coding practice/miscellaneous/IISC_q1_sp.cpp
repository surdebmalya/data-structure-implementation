/*
Password strong or not
atleast 1 -> lowercase, uppercase, number, spacial char {: ; < = > ? @} ASCII 58 - 64
*/

#include <iostream>
#include <cmath>
#include <vector>
#include <unordered_map>

using namespace std;

int strong_or_not(string psw) {
    unordered_map <string, int> un_map;
    un_map.insert(make_pair("lower", 0));
    un_map.insert(make_pair("upper", 0));
    un_map.insert(make_pair("number", 0));
    un_map.insert(make_pair("special", 0));

    auto it = psw.begin();
    while (it != psw.end()) {
        if (*it >= 'a' and *it <= 'z') {
            if (not(un_map["lower"])) {
                un_map["lower"]++;
            }
        }
        else if (*it >= 'A' and *it <= 'Z') {
            if (not(un_map["upper"])) {
                un_map["upper"]++;
            }
        }
        else if (*it >= '0' and *it <= '9') {
            if (not(un_map["number"])) {
                un_map["number"]++;
            }
        }
        else if (*it >= 58 and *it <= 64) {
            if (not(un_map["special"])) {
                un_map["special"]++;
            }
        }
        it++;
    }

    auto it_mp = un_map.begin();
    while (it_mp != un_map.end()) {
        if (it_mp->second==0) {
            return 0;
        }
        it_mp++;
    }
    return 1;
}

int main() {
    string psw;
    cin >> psw;
    cout << strong_or_not(psw) << endl;

    return 0;
}