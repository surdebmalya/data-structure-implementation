// https://leetcode.com/problems/3sum-closest/

// Medium

class Solution {
public:
    int threeSumClosest(vector<int> &nums, int target) {
        sort(nums.begin(), nums.end());
        int result, minDiff = INT_MAX;
        for (int i = 0; i < nums.size() - 2; i++) {
            int start = i + 1, end = nums.size() - 1;
            while (start < end) {
                int sum = nums[i] + nums[start] + nums[end];
                int diff = abs(sum - target);
                if (diff == 0)
                    return sum;
                else if (diff < minDiff) {
                    minDiff = diff;
                    result = sum;
                }

                if (sum < target)
                    start++;
                else
                    end--;
            }
        }
        return result;
    }
};