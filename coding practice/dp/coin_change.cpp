// https://leetcode.com/problems/coin-change/

// Medium

class Solution {
private:
    int recursion(vector<int> &coins, int remainingAmount, int currIndex, vector<vector<int>> &dp) {
        if (remainingAmount == 0)
            return 0;
        else if (remainingAmount < 0 or currIndex < 0)
            return INT_MAX - 1;
        else if (dp[currIndex][remainingAmount] != -1)
            return dp[currIndex][remainingAmount];
        int take = 1 + recursion(coins, remainingAmount - coins[currIndex], currIndex, dp);
        int skip = recursion(coins, remainingAmount, currIndex - 1, dp);
        dp[currIndex][remainingAmount] = min(take, skip);
        return dp[currIndex][remainingAmount];
    }

public:
    int coinChange(vector<int> &coins, int amount) {
        vector<vector<int>> dp(coins.size() + 1, vector<int>(amount + 1, -1));
        int result = recursion(coins, amount, coins.size() - 1, dp);
        return (result == INT_MAX - 1) ? -1 : result;
    }
};