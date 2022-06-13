// https://leetcode.com/problems/next-greater-element-i/

// Easy

class Solution {
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2) {
        int n = nums2.size();
        vector<int> nextGreater(n, -1);

        stack<int> s;
        s.push(nums2[n - 1]);
        for (int i = n - 2; i >= 0; i--) {
            if (s.top() > nums2[i]) {
                nextGreater[i] = s.top();
                s.push(nums2[i]);
            } else {
                while (!(s.empty()) and s.top() < nums2[i]) {
                    s.pop();
                }
                if (!(s.empty())) {
                    nextGreater[i] = s.top();
                }
                s.push(nums2[i]);
            }
        }

        unordered_map<int, int> m;
        for (int i = 0; i < nums2.size(); i++)
            m[nums2[i]] = nextGreater[i];

        vector<int> result(nums1.size(), -1);
        for (int i = 0; i < nums1.size(); i++) {
            result[i] = m[nums1[i]];
        }
        return result;
    }
};