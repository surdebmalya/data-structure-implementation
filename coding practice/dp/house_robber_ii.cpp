// https://www.codingninjas.com/codestudio/problems/house-robber_839733

// Medium

#include <bits/stdc++.h>
using namespace std;

long long int f(vector<int> &valueInHouse, vector<long long int> &dp, int currIndex) {
    if (currIndex < 0)
        return 0;
    if (dp[currIndex] != -1)
        return dp[currIndex];
    // take
    long long int take = valueInHouse[currIndex] + f(valueInHouse, dp, currIndex - 2);
    // skip
    long long int notTake = f(valueInHouse, dp, currIndex - 1);
    return dp[currIndex] = max(take, notTake);
}

long long int houseRobber(vector<int> &valueInHouse) {
    int n = valueInHouse.size();
    if (n == 1)
        return valueInHouse[0];
    vector<int> temp1, temp2;
    for (int i = 0; i < n; i++) {
        if (i != 0)
            temp1.push_back(valueInHouse[i]);
        if (i != n - 1)
            temp2.push_back(valueInHouse[i]);
    }
    vector<long long int> dp1(n, -1);
    long long int ans1 = f(temp1, dp1, temp1.size() - 1);

    vector<long long int> dp2(n, -1);
    long long int ans2 = f(temp2, dp2, temp2.size() - 1);
    return max(ans1, ans2);
}