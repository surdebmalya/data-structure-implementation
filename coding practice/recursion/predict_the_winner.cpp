// https://leetcode.com/problems/predict-the-winner/

// Medium

class Solution {
public:
    bool recur(vector<int> &nums, int i, int j, int total, bool turn) {
        if (i > j)
            return total >= 0;
        if (turn)
            return recur(nums, i + 1, j, total + nums[i], !turn) or recur(nums, i, j - 1, total + nums[j], !turn);

        return recur(nums, i + 1, j, total - nums[i], !turn) and recur(nums, i, j - 1, total - nums[j], !turn);
    }

    bool PredictTheWinner(vector<int> &nums) {

        return recur(nums, 0, nums.size() - 1, 0, true);
    }
};