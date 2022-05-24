// https://leetcode.com/problems/longest-valid-parentheses/

// Hard

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<pair<char, int>> st;    // <character, index>
        vector<vector<int>> tracking; // <startingIndex, endingIndex>
        for (int i = 0; i < s.size(); i++) {
            if (st.empty())
                st.push({s[i], i});
            else if (s[i] == '(')
                st.push({s[i], i});
            else { // s[i]==')'
                if (st.top().first == '(') {
                    tracking.push_back({st.top().second, i});
                    st.pop();
                } else
                    st.push({s[i], i});
            }
        }

        if (tracking.size() == 0)
            return 0;
        sort(tracking.begin(), tracking.end());
        int recentStart = tracking[0][0];
        int recentEnd = tracking[0][1];
        int result = 0;

        for (int i = 1; i < tracking.size(); i++) {
            if (tracking[i][0] - recentEnd == 1)
                recentEnd = tracking[i][1];
            else if (tracking[i][0] > recentStart and tracking[i][1] < recentEnd)
                continue;
            else if (tracking[i][0] - recentEnd != 1) {
                int diff = recentEnd - recentStart + 1;
                if (diff > result)
                    result = diff;
                recentStart = tracking[i][0];
                recentEnd = tracking[i][1];
            }
        }

        int diff = recentEnd - recentStart + 1;
        if (diff > result)
            result = diff;
        return result;
    }
};