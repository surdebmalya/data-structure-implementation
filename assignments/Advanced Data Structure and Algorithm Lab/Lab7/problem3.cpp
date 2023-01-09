// https://practice.geeksforgeeks.org/problems/longest-palindromic-subsequence-1612327878/1

class Solution{
    private:
    int solve(string s, int i, int j, vector<vector<int>> &dp) {
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==s[j]) {
            if(i==j) return dp[i][j]=1;
            else return dp[i][j]=2 + solve(s, i+1, j-1, dp);
        }
        return dp[i][j]=max(solve(s, i+1, j, dp), solve(s, i, j-1, dp));
    }
    
    public:
    int longestPalinSubseq(string s) {
        //code here
        vector<vector<int>> dp(s.size()+1, vector<int>(s.size()+1, -1));
        return solve(s, 0, s.size()-1, dp);
    }
};