// https://leetcode.com/problems/frequency-of-the-most-frequent-element/

// Medium

class Solution {
public:
    int maxFrequency(vector<int> &nums, int k) {
        sort(nums.begin(), nums.end());

        // sliding window prototype
        long int l = 0, r = 0;
        long int res = 0, sum = 0;
        while (r < nums.size()) {
            sum += nums[r];
            while (nums[r] * (r - l + 1) > k + sum) {
                sum -= nums[l];
                l++;
            }
            res = max(res, r - l + 1);
            r++;
        }
        return res;
    }
};