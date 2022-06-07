// https://leetcode.com/problems/sum-of-absolute-differences-in-a-sorted-array/

// Medium

class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int> &nums) {
        int n = nums.size();
        int sum = 0;
        for (int i = 0; i < n; i++)
            sum += nums[i];

        vector<int> result;
        int prev = 0, after = sum - nums[0];
        for (int i = 0; i < n; i++) {
            int temp = abs(prev - i * nums[i]) + abs(after - (n - 1 - i) * nums[i]);
            result.push_back(temp);
            prev += nums[i];
            if (i == n - 1)
                after = 0;
            else
                after -= nums[i + 1];
        }
        return result;
    }
};