// https://www.codingninjas.com/codestudio/problems/number-of-subsets_3952532

// Medium

#include <bits/stdc++.h>
using namespace std;

// int f(vector<int> &num, int tar, int currIndex, vector<vector<int>>& dp) {
//     if(currIndex==0) {
//         if(tar==0 or tar==num[0]) return 1;
//         else return 0;
//     }
//     if(dp[currIndex][tar]!=-1) return dp[currIndex][tar];
//     if(tar==0) return 1;
//     if(tar<0) return 0;
//     int take, skip;
//     // take
//     if(num[currIndex]<=tar)
//         take = f(num, tar-num[currIndex], currIndex-1, dp);
//     else take=0;
//     //skip
//     skip = f(num, tar, currIndex-1, dp);
//     return dp[currIndex][tar]=(take+skip);
// }

int findWays(vector<int> &num, int tar) {
    //     vector<vector<int>> dp(num.size(), vector<int>(tar+1, -1));
    //     return f(num, tar, num.size()-1, dp);
    vector<vector<int>> dp(num.size(), vector<int>(tar + 1, 0));
    for (int i = 0; i < num.size(); i++)
        dp[i][0] = 1;
    if (num[0] <= tar)
        dp[0][num[0]] = 1;
    for (int i = 1; i < num.size(); i++) {
        for (int j = 0; j <= tar; j++) {
            int take, skip;
            // take
            if (num[i] <= j)
                take = dp[i - 1][j - num[i]];
            else
                take = 0;
            // skip
            skip = dp[i - 1][j];
            dp[i][j] = (take + skip);
        }
    }
    return dp[num.size() - 1][tar];
}