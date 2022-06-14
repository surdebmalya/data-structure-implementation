// https://leetcode.com/problems/trapping-rain-water/

// Hard

class Solution {
public:
    int trap(vector<int> &height) {
        int n = height.size();
        vector<int> maxleft(n, -1), maxright(n, -1), mini(n, -1);
        maxleft[0] = 0, maxright[n - 1] = 0;

        int maxiL = height[0];
        for (int i = 1; i < n; i++) {
            maxleft[i] = maxiL;
            maxiL = max(maxiL, height[i]);
        }

        int maxiR = height[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            maxright[i] = maxiR;
            maxiR = max(maxiR, height[i]);
        }

        for (int i = 0; i < n; i++) {
            mini[i] = min(maxleft[i], maxright[i]);
        }

        int result = 0;
        for (int i = 0; i < n; i++) {
            if (mini[i] - height[i] > 0)
                result += mini[i] - height[i];
        }
        return result;
    }
};