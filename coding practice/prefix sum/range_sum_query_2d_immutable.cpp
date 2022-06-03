// https://leetcode.com/problems/range-sum-query-2d-immutable/

// Medium

class NumMatrix {
    vector<vector<int>> arr;

public:
    NumMatrix(vector<vector<int>> &matrix) {
        // making the actual grids
        int ROW = matrix.size();
        int COL = matrix[0].size();
        for (int i = 0; i <= ROW; i++) {
            vector<int> temp;
            for (int j = 0; j <= COL; j++)
                temp.push_back(0);
            arr.push_back(temp);
        }

        for (int i = 1; i <= ROW; i++) {
            int left = 0;
            for (int j = 1; j <= COL; j++) {
                arr[i][j] = matrix[i - 1][j - 1] + arr[i - 1][j] + left;
                left += matrix[i - 1][j - 1];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        row1 = row1 + 1;
        col1 = col1 + 1;
        row2 = row2 + 1;
        col2 = col2 + 1;
        return arr[row2][col2] - arr[row2][col1 - 1] - arr[row1 - 1][col2] + arr[row1 - 1][col1 - 1];
    }
};