// https://leetcode.com/problems/minimum-path-sum/

// Medium

class Solution {
private:
    int f(vector<vector<int>> &grid, int currRow, int currCol, vector<vector<int>> &dp) {
        if (currRow < 0 or currCol < 0)
            return INT_MAX;
        else if (dp[currRow][currCol] != -1)
            return dp[currRow][currCol];
        else if (currRow == 0 and currCol == 0)
            return dp[currRow][currCol] = grid[currRow][currCol];
        // up
        int up = f(grid, currRow - 1, currCol, dp);
        // left
        int left = f(grid, currRow, currCol - 1, dp);
        return dp[currRow][currCol] = min(up, left) + grid[currRow][currCol];
    }

public:
    int minPathSum(vector<vector<int>> &grid) {
        int ROW = grid.size();
        int COL = grid[0].size();
        vector<vector<int>> dp(ROW, vector<int>(COL, -1));
        return f(grid, grid.size() - 1, grid[0].size() - 1, dp);
    }
};