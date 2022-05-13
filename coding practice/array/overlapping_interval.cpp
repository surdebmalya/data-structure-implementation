// https://practice.geeksforgeeks.org/problems/8a644e94faaa94968d8665ba9e0a80d1ae3e0a2d/1/

// Medium

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    vector<vector<int>> overlappedInterval(vector<vector<int>> &intervals) {
        if (intervals.size() == 1) {
            return intervals;
        }
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> result;
        int start = intervals[0][0];
        int end = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] <= end) {
                end = max(intervals[i][1], end);
            } else {
                result.push_back({start, end});
                start = intervals[i][0];
                end = intervals[i][1];
            }
        }
        result.push_back({start, end});
        return result;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<vector<int>> Intervals(n);
        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            Intervals[i].push_back(x);
            Intervals[i].push_back(y);
        }
        Solution obj;
        vector<vector<int>> ans = obj.overlappedInterval(Intervals);
        for (auto i : ans) {
            for (auto j : i) {
                cout << j << " ";
            }
        }
        cout << "\n";
    }
    return 0;
} // } Driver Code Ends