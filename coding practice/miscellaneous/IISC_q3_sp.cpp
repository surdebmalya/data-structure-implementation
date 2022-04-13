/*
Finding median of unknown number of inputs
*/

#include <cmath>
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

float find_median(vector<int> &v) {
    int n = v.size();
    if (n % 2 == 0) {
        return float(v[n / 2] + v[(n / 2) - 1])/float(2);
    } else {
        return v[floor(n / 2)];
    }
}

void adjust(vector<int> &v) {
    if (v.size() == 1) {
        return;
    } else {
        int newly_added_ele = v[v.size() - 1];
        int last_index_that_swapped = v.size() - 1;
        for (int index = v.size() - 2; index >= 0; index--) {
            if (v[index] > newly_added_ele) {
                v[index + 1] = v[index];
                last_index_that_swapped = index;
            } else {
                break;
            }
        }
        if (last_index_that_swapped != v.size() - 1) {
            v[last_index_that_swapped] = newly_added_ele;
        }
    }
}

int main() {
    vector<int> v;
    int num;
    while (cin >> num) {
        v.push_back(num);
        adjust(v);
    }
    cout << setprecision(1) << fixed;
    cout << "Median: " << find_median(v) << endl;

    return 0;
}