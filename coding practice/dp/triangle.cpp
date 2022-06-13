// https://leetcode.com/problems/triangle/

// Medium

class Solution {
public:
    int minimumTotal(vector<vector<int>> &triangle) {
        int row = triangle.size(), col = triangle[triangle.size() - 1].size();
        vector<int> prev;

        // tabulation method + memory optimization
        for (int i = 0; i < col; i++) {
            prev.push_back(triangle[triangle.size() - 1][i]);
        }
        for (int i = row - 2; i >= 0; i--) {
            vector<int> curr(i + 1, -1);
            for (int j = 0; j <= i; j++) {
                // down
                int down = prev[j];
                // right
                int right = prev[j + 1];
                curr[j] = min(down, right) + triangle[i][j];
            }
            prev = curr;
        }
        return prev[0];
    }
};