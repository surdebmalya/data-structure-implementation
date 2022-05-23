// https://leetcode.com/problems/triangle/

// Medium

class Solution {
private:
    int f(vector<vector<int>> &triangle, int currRow, int currCol, vector<vector<int>> &dp) {
        if (currRow >= triangle.size())
            return 0;
        else if (dp[currRow][currCol] != -1)
            return dp[currRow][currCol];
        // left
        int left = f(triangle, currRow + 1, currCol, dp);
        // right
        int right = f(triangle, currRow + 1, currCol + 1, dp);
        return dp[currRow][currCol] = min(left, right) + triangle[currRow][currCol];
    }

public:
    int minimumTotal(vector<vector<int>> &triangle) {
        if (triangle.size() == 1)
            return triangle[0][0];
        vector<vector<int>> dp;
        for (int i = 0; i < triangle.size(); i++) {
            vector<int> temp(i + 1, -1);
            dp.push_back(temp);
        }
        return f(triangle, 0, 0, dp);
    }
};