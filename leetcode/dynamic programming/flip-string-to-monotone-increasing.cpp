class Solution {
public:
    int solve(string &s, int index, int prev, vector<vector<int>>& dp) {
        if(index==s.size()) return 0;
        if(dp[index][prev]!=-1) return dp[index][prev];
        int flip=INT_MAX, nonFlip=INT_MAX;
        if(s[index]=='0') {
            if(prev==0) {
                flip = 1 + solve(s, index+1, 1, dp);
                nonFlip = solve(s, index+1, 0, dp);
            }
            else {
                flip = 1 + solve(s, index+1, 1, dp);
            }
        }
        else { // 1
            if(prev==0) {
                flip = 1 + solve(s, index+1, 0, dp);
                nonFlip = solve(s, index+1, 1, dp);
            }
            else {
                nonFlip = solve(s, index+1, 1, dp);
            }
        }
        return dp[index][prev]=min(flip, nonFlip);
    }
    int minFlipsMonoIncr(string s) {
        vector<vector<int>> dp(s.size()+1, vector<int>(2, -1));
        return solve(s, 0, 0, dp);
    }
};