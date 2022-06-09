// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

// Medium

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        int start = 0, end = nums.size() - 1;
        while (start <= end) {
            int sum = nums[start] + nums[end];
            if (sum == target)
                return {start + 1, end + 1};
            else if (sum < target)
                start++;
            else
                end--;
        }
        return {-1, -1};
    }
};