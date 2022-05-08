// https://leetcode.com/problems/combination-sum-ii/

// Madium

class Solution {
private:
    vector<vector<int>> result;

    void backtracking(vector<int> &nums, int remaining, vector<int> arr, int index) {
        if (index == nums.size() or remaining <= 0) {
            if (remaining == 0) {
                result.push_back(arr);
            }
            return;
        }
        // pick the element
        arr.push_back(nums[index]);
        backtracking(nums, remaining - nums[index], arr, index + 1);
        arr.pop_back();

        // remove duplicates
        while (index < nums.size() - 1 and nums[index] == nums[index + 1])
            index++;
        if (index == nums.size()) {
            return;
        }

        // don't pick the element
        backtracking(nums, remaining, arr, index + 1);
    }

public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        backtracking(candidates, target, temp, 0);
        return result;
    }
};