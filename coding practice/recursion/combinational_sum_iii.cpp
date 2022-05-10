// https://leetcode.com/problems/combination-sum-iii/

// Medium

class Solution {
private:
    void backtracking(int k, int sum, int curr_num, vector<int> &arr, vector<vector<int>> &result) {
        if (k == 0 and sum == 0) {
            result.push_back(arr);
            return;
        }
        if ((k == 0 and sum != 0) or (k != 0 and sum == 0)) {
            return;
        }
        if (curr_num > 9) {
            return;
        }
        arr.push_back(curr_num);
        if (sum - curr_num >= 0)
            backtracking(k - 1, sum - curr_num, curr_num + 1, arr, result);

        arr.pop_back();
        backtracking(k, sum, curr_num + 1, arr, result);
    }

public:
    vector<vector<int>> combinationSum3(int k, int sum) {
        vector<vector<int>> result;
        int lower_value = 0;
        for (int i = 1; i <= k; i++) {
            lower_value += i;
        }
        int higher_value = 0;
        for (int j = 9; j > 9 - k; j--) {
            higher_value += j;
        }
        if (sum < lower_value or sum > higher_value) {
            return result;
        }

        vector<int> temp;
        backtracking(k, sum, 1, temp, result);
        return result;
    }
};