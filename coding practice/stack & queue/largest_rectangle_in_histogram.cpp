// https://leetcode.com/problems/largest-rectangle-in-histogram/

// Hard

class Solution {
public:
    int largestRectangleArea(vector<int> &heights) {
        // solve using stack
        stack<pair<int, int>> s; // index, height
        int area = 0;
        int extendedIndex = -1;
        for (int i = 0; i < heights.size(); i++) {
            if (s.empty()) {
                s.push({i, heights[i]});
            } else {
                if (heights[i] > s.top().second) {
                    s.push({i, heights[i]});
                } else {
                    // current height is less than or equals to
                    while (!(s.empty()) and s.top().second >= heights[i]) {
                        pair<int, int> recent = s.top();
                        s.pop();
                        extendedIndex = recent.first;
                        int tempArea = recent.second * (i - recent.first);
                        area = max(area, tempArea);
                    }
                    if (s.empty())
                        s.push({0, heights[i]});
                    else
                        s.push({extendedIndex, heights[i]});
                }
            }
        }

        int ultimateIndex = heights.size();
        while (!(s.empty())) {
            pair<int, int> recent = s.top();
            s.pop();
            int tempArea = recent.second * (ultimateIndex - recent.first);
            area = max(area, tempArea);
        }

        return area;
    }
};