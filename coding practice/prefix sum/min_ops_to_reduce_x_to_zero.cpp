// https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/

// Medium

class Solution {
public:
    int minOperations(vector<int> &nums, int x) {
        // prefix sum. Just find (sum-x) subarray
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
            sum += nums[i];
        if (sum == x)
            return nums.size();
        sum = sum - x;
        int length = -1;
        unordered_map<int, int> um;
        um[0] = -1;
        int prefix = 0;
        for (int i = 0; i < nums.size(); i++) {
            prefix += nums[i];
            if (um.find(prefix - sum) == um.end()) {
                um[prefix] = i;
            } else {
                length = max(length, i - um[prefix - sum]);
                um[prefix] = i;
            }
        }
        if (length == -1)
            return length;
        else
            return nums.size() - length;
    }
};