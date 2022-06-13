// https://leetcode.com/problems/next-greater-element-ii/

// Medium

class Solution {
public:
    vector<int> nextGreaterElements(vector<int> &nums) {
        int n = nums.size();
        vector<int> workable = nums;
        for (int i = 0; i < n; i++)
            workable.push_back(nums[i]);
        vector<int> temp(2 * n, -1);

        stack<int> s;
        s.push(workable[2 * n - 1]);
        for (int i = 2 * n - 2; i >= 0; i--) {
            if (s.top() > workable[i]) {
                temp[i] = s.top();
                s.push(workable[i]);
            } else {
                while (!(s.empty()) and s.top() <= workable[i]) {
                    s.pop();
                }
                if (!(s.empty())) {
                    temp[i] = s.top();
                }
                s.push(workable[i]);
            }
        }
        vector<int> result;
        for (int i = 0; i < n; i++) {
            result.push_back(temp[i]);
        }
        return result;
    }
};