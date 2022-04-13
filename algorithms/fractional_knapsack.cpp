#include <algorithm> // to use sort()
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int fractional_knapsack(vector<int> &val, vector<int> &wt, int W) {
}

int main() {
    vector<int> val = {60, 100, 120};
    vector<int> wt = {10, 20, 30};
    int W = 50;
    cout << fractional_knapsack(val, wt, W) << endl;

    return 0;
}