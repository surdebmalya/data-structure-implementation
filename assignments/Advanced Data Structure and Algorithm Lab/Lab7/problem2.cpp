// https://practice.geeksforgeeks.org/problems/coin-change2448/1

class Solution {
    private:
    long long int solve(int coins[], int N, int sum, int index, long long int dp[1001][1001]) {
        if(sum==0) return 1;
        if(dp[sum][index]!=-1) return dp[sum][index];
        if(index<0) {
            if(sum==0) return 1;
            else return 0;
        }
        if(coins[index]<=sum) {
            // take and non-take situation
            return dp[sum][index]=solve(coins, N, sum-coins[index], index, dp) + solve(coins, N, sum, index-1, dp);
        }
        else {
            return dp[sum][index]=solve(coins, N, sum, index-1, dp);
        }
    }
    
    public:
    long long int count(int coins[], int N, int sum) {
        // code here.
        long long int dp[1001][1001];
        memset(dp, -1, sizeof(dp));
        return solve(coins, N, sum, N-1, dp);
    }
};