// https://www.hackerrank.com/challenges/cpp-maps/problem?isFullScreen=true&h_r=next-challenge&h_v=zen

// Easy

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;


int main() {
    unordered_map<string, int> m;
    int t;
    int id, marks;
    string name;
    cin >>t;
    while (t) {
        --t;
        cin >> id;
        if (id==1) {
            cin >> name >> marks;
            if (m.count(name) != 0) {
                m[name] = m[name] + marks;
            }
            else {
                m.insert(make_pair(name, marks));
            }
        }
        else if (id==2) {
            cin >> name;
            m.erase(name);
        }
        else if (id==3) {
            cin >> name;
            if (m.count(name) != 0) {
                cout << m[name] << endl;
            }
            else {
                cout << 0 << endl;
            }
        }
    }
    return 0;
}
