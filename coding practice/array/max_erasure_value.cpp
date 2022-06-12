// https://leetcode.com/problems/maximum-erasure-value/

// Medium

class Solution {
public:
    int maximumUniqueSubarray(vector<int> &nums) {
        int l = 0, r = 0;
        int maxi = 0;
        unordered_set<int> tracing;
        int currentSum = 0;
        while (r < nums.size()) {
            if (tracing.find(nums[r]) == tracing.end()) {
                tracing.insert(nums[r]);
                currentSum += nums[r];
                r++;
            } else {
                maxi = max(maxi, currentSum);
                while (tracing.find(nums[r]) != tracing.end()) {
                    currentSum -= nums[l];
                    tracing.erase(tracing.find(nums[l]));
                    l++;
                }
            }
        }
        maxi = max(maxi, currentSum);
        return maxi;
    }
};