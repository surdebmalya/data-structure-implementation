// https://www.codingninjas.com/codestudio/problems/subset-sum-equal-to-k_1550954

// Medium

#include <bits/stdc++.h>
using namespace std;

bool f(int currIndex, vector<int>& arr, int k, int currSum, vector<vector<int>>& dp) {
    if(currSum==k) return true;
    if(currIndex<0 or currSum>k) return false;
    if(dp[currIndex][currSum]!=-1) return dp[currIndex][currSum];
    // take
    bool take = f(currIndex-1, arr, k, currSum+arr[currIndex], dp);
    if (take) return dp[currIndex][currSum]=true;
    // skip
    bool skip = f(currIndex-1, arr, k, currSum, dp);
    if (skip) return dp[currIndex][currSum]=true;
    return dp[currIndex][currSum]=false;
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<int>> dp(n, vector<int> (k+1, -1));
    return f(n-1, arr, k, 0, dp);
}