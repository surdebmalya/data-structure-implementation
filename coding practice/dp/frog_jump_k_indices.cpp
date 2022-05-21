#include <bits/stdc++.h>
using namespace std;

// Recursion solution
/*
int recursion(vector<int> &heights, int n, int steps) {
    if (n == 0)
        return 0;
    int result = INT_MAX;
    for (int i = 1; i <= steps; i++) {
        if (n - i >= 0) {
            int val = recursion(heights, n - i, steps) + abs(heights[n] - heights[n - i]);
            result = min(val, result);
        }
    }
    return result;
}
*/

// Memoization solution
/*
int memoization(vector<int> &dp, vector<int> &heights, int n, int steps) {
    if (n == 0)
        return 0;
    if (dp[n] != -1)
        return dp[n];
    int result = INT_MAX;
    for (int i = 1; i <= steps; i++) {
        if (n - i >= 0) {
            int val = memoization(dp, heights, n - i, steps) + abs(heights[n] - heights[n - i]);
            result = min(val, result);
        }
    }
    return dp[n] = result;
}
*/

// Tabulation solution
int tabulation(vector<int> &dp, vector<int> &heights, int n, int steps) {
    dp[0] = 0;
    for (int j = 1; j < n; j++) {
        int result = INT_MAX;
        for (int i = 1; i <= steps; i++) {
            if (j - i >= 0) {
                int val = dp[j - i] + abs(heights[j] - heights[j - i]);
                result = min(val, result);
            }
        }
        dp[j] = result;
    }
    return dp[n - 1];
}

int main() {
    vector<int> heights{30, 10, 60, 10, 60, 50};
    int n = heights.size();
    int k = 2;

    // int result = recursion(heights, n-1, k);

    // vector<int> dp(n + 1, -1);
    // int result = memoization(dp, heights, n - 1, k);

    vector<int> dp(n, -1);
    int result = tabulation(dp, heights, n, k);

    cout << "Minimum energy required: " << result << endl;

    return 0;
}