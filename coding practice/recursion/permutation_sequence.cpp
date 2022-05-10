// https://leetcode.com/problems/permutation-sequence/

// Hard

class Solution {
private:
    string result = "";
    int fact(int n) {
        int result = 1;
        while (n != 1) {
            result *= n;
            n--;
        }
        return result;
    }
    void recursion(int n, int k, vector<int> &nums) {
        if (k == 0) {
            for (int index = 0; index < nums.size(); index++) {
                result += to_string(nums[index]);
            }
            return;
        }
        int d = k / fact(n - 1);
        result += to_string(nums[d]);
        nums.erase(nums.begin() + d);
        recursion(n - 1, k % fact(n - 1), nums);
    }

public:
    string getPermutation(int n, int k) {
        k = k - 1;
        vector<int> nums;
        for (int index = 1; index <= n; index++) {
            nums.push_back(index);
        }
        recursion(n, k, nums);
        return result;
    }
};