// https://www.hackerrank.com/challenges/variable-sized-arrays/problem?isFullScreen=true

// Easy

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n, q, num_ele, ele;
    cin >> n >> q;
    vector<vector <int>> evec;
    for (int i=0; i<n; ++i) {
        cin >> num_ele;
        vector<int> ivec;
        for (int j=0; j<num_ele; ++j) {
            cin >> ele;
            ivec.push_back(ele);
        }
        evec.push_back(ivec);
    }
    int row, col;
    while (q) {
        cin >> row >> col;
        cout << evec[row][col] << endl;
        --q;
    }
    
    return 0;
}
