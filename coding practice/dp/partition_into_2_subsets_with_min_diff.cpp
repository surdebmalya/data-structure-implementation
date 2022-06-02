// https://www.codingninjas.com/codestudio/problems/partition-a-set-into-two-subsets-such-that-the-difference-of-subset-sums-is-minimum_842494

// Hard

#include <bits/stdc++.h>
int minSubsetSumDifference(vector<int> &arr, int n) {
    int s = 0;
    for (int i = 0; i < n; i++)
        s += arr[i];

    vector<vector<bool>> dp(n, vector<bool>(s + 1, false));
    for (int i = 0; i < n; i++)
        dp[i][0] = true;
    if (arr[0] <= s)
        dp[0][arr[0]] = true;
    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= s; j++) {
            bool take = false;
            if (arr[i] <= j)
                take = dp[i - 1][j - arr[i]];
            bool skip = dp[i - 1][j];
            dp[i][j] = (take or skip);
        }
    }

    int result = 1e9;
    for (int i = 0; i <= s; i++) {
        if (dp[n - 1][i] == true) {
            int diff1 = i;
            int diff2 = s - i;
            int temp = abs(diff1 - diff2);
            result = min(result, temp);
        }
    }
    return result;
}
