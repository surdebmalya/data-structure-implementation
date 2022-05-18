// https://leetcode.com/problems/generate-parentheses/

// Medium

class Solution {
    void backtracking(string curr, int open, int close, int n, vector<string> &result) {
        if (open == close) {
            if (open == n) {
                result.push_back(curr);
                return;
            } else {
                curr += '(';
                backtracking(curr, open + 1, close, n, result);
            }
        } else if (open == n) {
            curr += ')';
            backtracking(curr, open, close + 1, n, result);
        } else if (open > close) {
            curr += '(';
            backtracking(curr, open + 1, close, n, result);
            curr = curr.substr(0, curr.size() - 1);
            curr += ')';
            backtracking(curr, open, close + 1, n, result);
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        // backtracking solution
        vector<string> result;
        backtracking("", 0, 0, n, result);
        return result;
    }
};