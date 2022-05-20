// https://leetcode.com/problems/unique-paths-ii/

// Medium

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
        // Top down approach
        int ROW = obstacleGrid.size();
        int COL = obstacleGrid[0].size();
        vector<vector<int>> dp(ROW + 1, vector<int>(COL + 1, 0));
        dp[1][0] = 1;
        for (int i = 1; i < ROW + 1; i++) {
            for (int j = 1; j < COL + 1; j++) {
                if (!(obstacleGrid[i - 1][j - 1]))
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[ROW][COL];
    }
};