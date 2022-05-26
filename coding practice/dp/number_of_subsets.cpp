// https://www.codingninjas.com/codestudio/problems/number-of-subsets_3952532

// Medium

#include <bits/stdc++.h>
using namespace std;

int f(vector<int> &num, int tar, int currIndex, vector<vector<int>>& dp) {
    if(currIndex<0) {
        if(tar==0) return 1;
        else return 0;
    }
    if(dp[currIndex][tar]!=-1) return dp[currIndex][tar];
    if(tar==0) return 1;
    if(tar<0) return 0;
    int take, skip;
    // take
    if(num[currIndex]<=tar) 
        take = f(num, tar-num[currIndex], currIndex-1, dp);
    else take=0;
    //skip
    skip = f(num, tar, currIndex-1, dp);
    return dp[currIndex][tar]=(take+skip);
}

int findWays(vector<int> &num, int tar) {
    vector<vector<int>> dp(num.size(), vector<int>(tar+1, -1));
    return f(num, tar, num.size()-1, dp);
}