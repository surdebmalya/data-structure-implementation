// https://leetcode.com/problems/permutations-ii/

// Medium

class Solution {
private:
    set<vector<int>> us;
    void permutation(vector<int> &nums, int index, vector<vector<int>> &result) {
        if ((index == (nums.size() - 1)) and (us.find(nums) == us.end())) {
            result.push_back(nums);
            us.insert(nums);
            return;
        }
        for (int i = index; i < nums.size(); i++) {
            if (i == index) {
                permutation(nums, index + 1, result);
            } else {
                while ((i < nums.size()) and (nums[i] == nums[i - 1]) and nums[index] != nums[i]) {
                    i++;
                }
                if (i != nums.size()) {
                    swap(nums[index], nums[i]);
                    permutation(nums, index + 1, result);
                    swap(nums[index], nums[i]);
                }
            }
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int> &nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        permutation(nums, 0, result);
        return result;
    }
};