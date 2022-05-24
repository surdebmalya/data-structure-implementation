// https://www.codingninjas.com/codestudio/problems/maximum-path-sum-in-the-matrix_797998

// Medium

#include <bits/stdc++.h>
using namespace std;

int f(vector<vector<int>> &matrix, int currRow, int currCol, vector<vector<int>> &dp) {
    if (currRow == matrix.size() - 1 and (currCol >= 0 and currCol <= matrix[0].size() - 1))
        return dp[currRow][currCol] = matrix[currRow][currCol];
    if (currCol < 0 or currCol >= matrix[0].size())
        return INT_MIN;
    if (dp[currRow][currCol] != -1)
        return dp[currRow][currCol];
    int left = f(matrix, currRow + 1, currCol - 1, dp);
    int right = f(matrix, currRow + 1, currCol + 1, dp);
    int down = f(matrix, currRow + 1, currCol, dp);
    int result = max(left, max(right, down)) + matrix[currRow][currCol];
    dp[currRow][currCol] = result;
    return result;
}

int getMaxPathSum(vector<vector<int>> &matrix) {
    vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), -1));
    int result = INT_MIN;
    for (int i = 0; i < matrix[0].size(); i++) {
        int temp = f(matrix, 0, i, dp);
        if (temp > result)
            result = temp;
    }
    return result;
}