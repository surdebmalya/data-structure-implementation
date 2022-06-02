// https://leetcode.com/problems/transpose-matrix/

// Easy

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>> &matrix) {
        vector<vector<int>> result(matrix[0].size(), vector<int>(matrix.size(), -1));
        for (int ROW = 0; ROW < matrix[0].size(); ROW++) {
            for (int COL = 0; COL < matrix.size(); COL++)
                result[ROW][COL] = matrix[COL][ROW];
        }
        return result;
    }
};