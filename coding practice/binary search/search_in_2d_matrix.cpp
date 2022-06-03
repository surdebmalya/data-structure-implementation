// https://leetcode.com/problems/search-a-2d-matrix/

// Medium

class Solution {
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        int ROW = matrix.size();
        int COL = matrix[0].size();
        int start = 0, end = ROW * COL - 1;
        while (start <= end) {
            int mid = (start + end) / 2;
            int r = mid / COL, c = mid % COL;
            if (matrix[r][c] == target)
                return true;
            else if (matrix[r][c] < target)
                start = mid + 1;
            else
                end = mid - 1;
        }
        return false;
    }
};