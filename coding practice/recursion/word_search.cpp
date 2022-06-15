// https://leetcode.com/problems/word-search/

// Medium

class Solution {
private:
    bool f(string &str, int index, vector<vector<char>> &board, vector<vector<bool>> &visited, int row, int col) {
        if (index >= str.size())
            return true;
        int ROW = board.size(), COL = board[0].size();
        if ((row >= 0 and row < ROW) and (col >= 0 and col < COL)) {
            if ((board[row][col] == str[index]) and (visited[row][col] == false)) {
                visited[row][col] = true;
                bool up = f(str, index + 1, board, visited, row - 1, col);
                bool down = f(str, index + 1, board, visited, row + 1, col);
                bool left = f(str, index + 1, board, visited, row, col - 1);
                bool right = f(str, index + 1, board, visited, row, col + 1);
                visited[row][col] = false;
                return (up or down or left or right);
            } else
                return false;
        } else
            return false;
    }

public:
    bool exist(vector<vector<char>> &board, string word) {
        // backtracking problem
        int ROW = board.size(), COL = board[0].size();
        vector<vector<bool>> visited(ROW, vector<bool>(COL, false));
        bool ans = false;
        for (int i = 0; i < ROW; i++) {
            for (int j = 0; j < COL; j++) {
                if (board[i][j] == word[0]) {
                    visited[i][j] = true;
                    bool up = f(word, 1, board, visited, i - 1, j);
                    bool down = f(word, 1, board, visited, i + 1, j);
                    bool left = f(word, 1, board, visited, i, j - 1);
                    bool right = f(word, 1, board, visited, i, j + 1);

                    ans = (ans or up or down or left or right);
                    if (ans)
                        return true;
                    visited[i][j] = false;
                }
            }
        }
        return false;
    }
};