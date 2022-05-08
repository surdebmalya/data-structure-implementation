// https://leetcode.com/problems/subsets-ii/

// Medium

class Solution {
public:
    void recur(vector<int> &nums, vector<vector<int>> &result, vector<int> &arr, int index) {
        if (index >= nums.size()) {
            result.push_back(arr);
            return;
        }
        // take
        arr.push_back(nums[index]);
        recur(nums, result, arr, index + 1);
        arr.pop_back();

        // skip
        while (index < nums.size() - 1 and nums[index] == nums[index + 1]) {
            index++;
        }
        recur(nums, result, arr, index + 1);
    }
    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
        vector<vector<int>> result;
        vector<int> temp;
        sort(nums.begin(), nums.end());
        recur(nums, result, temp, 0);
        return result;
    }
};