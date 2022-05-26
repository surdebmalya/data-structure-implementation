// https://www.codingninjas.com/codestudio/problems/ninja-and-his-friends_3125885

// Hard

#include <bits/stdc++.h>
using namespace std;

int f(int i, int j1, int j2, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp) {
    int r = grid.size(), c = grid[0].size();
    if (j1 < 0 or j1 >= c or j2 < 0 or j2 >= c)
        return -1e8;
    if (dp[i][j1][j2] != -1)
        return dp[i][j1][j2];
    if (i == r - 1) {
        if (j1 == j2)
            return dp[i][j1][j2] = grid[i][j1];
        else
            return dp[i][j1][j2] = grid[i][j1] + grid[i][j2];
    }
    // explore every possibilities
    int maxi = INT_MIN;
    for (int col1 = -1; col1 <= 1; col1++) {
        for (int col2 = -1; col2 <= 1; col2++) {
            int value = 0;
            if (j1 == j2)
                value = grid[i][j1];
            else
                value = grid[i][j1] + grid[i][j2];
            value += f(i + 1, j1 + col1, j2 + col2, grid, dp);
            maxi = max(maxi, value);
        }
    }
    return dp[i][j1][j2] = maxi;
}

int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    vector<vector<vector<int>>> dp(r + 1, vector<vector<int>>(c + 1, vector<int>(c + 1, -1)));
    return f(0, 0, c - 1, grid, dp);
}