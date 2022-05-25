// https://www.codingninjas.com/codestudio/problems/subset-sum-equal-to-k_1550954

// Medium

#include <bits/stdc++.h>
using namespace std;

bool f(vector<int>& arr, int currIndex, int k, vector<vector<int>>& dp) {
    if(currIndex==0) {
        if(k==0 or k==arr[currIndex]) return true;
        else return false;
    }
    if(dp[currIndex][k]!=-1) return dp[currIndex][k];
    // take
    bool take = false;
    if(k>=arr[currIndex])
        take = f(arr, currIndex-1, k-arr[currIndex], dp);
    // skip
    bool skip = f(arr, currIndex-1, k, dp);
    return dp[currIndex][k]=(take or skip);
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
//     vector<vector<int>> dp(n, vector<int>(k+1, -1));
//     return f(arr, arr.size()-1, k, dp);
    vector<vector<bool>> dp(n, vector<bool>(k+1, false));
    for(int i=0; i<n; i++) dp[i][0]=true;
    if(arr[0]<=k) dp[0][arr[0]]=true;
    for(int i=1; i<n; i++) {
        for(int target=1; target<=k; target++) {
            bool take = false;
            if(target>=arr[i])
                take = dp[i-1][target-arr[i]];
            // skip
            bool skip = dp[i-1][target];
            dp[i][target]=(take or skip);
        }
    }
    return dp[n-1][k];
}