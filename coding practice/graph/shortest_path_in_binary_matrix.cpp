// https://leetcode.com/problems/shortest-path-in-binary-matrix/

// Medium

class Solution {
    bool isValid(int row, int col, vector<vector<int>> &grid, vector<vector<bool>> &visited) {
        int n = grid.size();
        if (row >= 0 and row < n and col >= 0 and col < n and grid[row][col] == 0) {
            if (!(visited[row][col])) {
                visited[row][col] = true;
                return true;
            } else {
                return false;
            }
        } else {
            return false;
        }
    }

public:
    int shortestPathBinaryMatrix(vector<vector<int>> &grid) {
        int n = grid.size();
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        int totalNumberOfLvls = -1;
        // assuming level starts from 1
        queue<pair<pair<int, int>, int>> q; // pair<pair<row, col>, currLvl>
        if (grid[0][0] == 0) {
            q.push({{0, 0}, 1});
        }
        while (!(q.empty())) {
            pair<pair<int, int>, int> node = q.front();
            int ROW = node.first.first, COL = node.first.second;
            int currLvl = node.second;
            q.pop();
            if (ROW == n - 1 and COL == n - 1 and isValid(n - 1, n - 1, grid, visited))
                totalNumberOfLvls = currLvl;
            else if (isValid(ROW, COL, grid, visited)) {
                q.push({{ROW - 1, COL - 1}, currLvl + 1});
                q.push({{ROW - 1, COL}, currLvl + 1});
                q.push({{ROW - 1, COL + 1}, currLvl + 1});
                q.push({{ROW, COL - 1}, currLvl + 1});
                q.push({{ROW, COL + 1}, currLvl + 1});
                q.push({{ROW + 1, COL - 1}, currLvl + 1});
                q.push({{ROW + 1, COL}, currLvl + 1});
                q.push({{ROW + 1, COL + 1}, currLvl + 1});
            }
        }
        return totalNumberOfLvls;
    }
};