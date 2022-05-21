// https://www.codingninjas.com/codestudio/problems/maximum-sum-of-non-adjacent-elements_843261

// Medium

#include <bits/stdc++.h>
using namespace std;

// int recursion(vector<int>& nums, int index) {
// 	if(index<0) return 0;
// 	// take
// 	int take = nums[index] + recursion(nums, index-2);
// 	// skip
// 	int skip = recursion(nums, index-1);
// 	return max(take, skip);
// }

int memoization(vector<int> &nums, int index, vector<int> &dp) {
    if (index < 0)
        return 0;
    if (dp[index] != -1)
        return dp[index];
    // take
    int take = nums[index] + memoization(nums, index - 2, dp);
    // skip
    int skip = memoization(nums, index - 1, dp);
    return dp[index] = max(take, skip);
}

int maximumNonAdjacentSum(vector<int> &nums) {
    int n = nums.size();
    vector<int> dp(n + 1, -1);
    // return recursion(nums, n-1);
    return memoization(nums, n - 1, dp);
}