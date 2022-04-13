#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int knapsack_0_1(vector<int> &val, vector<int> &wt, int W, int index) {
    if (index < 0) {
        return 0;
    }
    if (W >= wt[index]) {
        return max(val[index] + knapsack_0_1(val, wt, W - wt[index], index - 1),
                knapsack_0_1(val, wt, W, index - 1));
    } else {
        return 0;
    }
}

int main() {
    vector<int> val = {60, 100, 120};
    vector<int> wt = {10, 20, 30};
    int W = 50;
    int index = val.size() - 1;
    cout << knapsack_0_1(val, wt, W, index) << endl;

    return 0;
}