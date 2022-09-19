// https://practice.geeksforgeeks.org/problems/rod-cutting0840/1

class Solution{
    private:
    int solve(int price[], int index, int wt, int dp[1001][1001]) {
        if(index<0 or wt==0) return 0;
        if(dp[index][wt]!=-1) return dp[index][wt];
        if(index+1<=wt) {
            return dp[index][wt]=max(price[index]+solve(price, index, wt-(index+1), dp), solve(price, index-1, wt, dp));
        }
        else {
            return dp[index][wt]=solve(price, index-1, wt, dp);
        }
    }
    
    public:
    int cutRod(int price[], int n) {
        //code here
        int dp[1001][1001];
        memset(dp, -1, sizeof(dp));
        return solve(price, n-1, n, dp);
    }
};