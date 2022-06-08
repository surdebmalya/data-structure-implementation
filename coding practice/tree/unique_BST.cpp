// https://leetcode.com/problems/unique-binary-search-trees/

// Medium

class Solution {
private:
    int f(int n, vector<int> &dp) {
        if (dp[n] != -1)
            return dp[n];
        if (n == 0 or n == 1)
            return dp[n] = 1;
        int total = 0;
        for (int i = 1; i <= n; i++) {
            int left = f(i - 1, dp);
            int right = f(n - i, dp);
            total += (left * right);
        }
        return dp[n] = total;
    }

public:
    int numTrees(int n) {
        vector<int> dp(20, -1);
        return f(n, dp);
    }
};