class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end());
        int start = intervals[0][0], end = intervals[0][1];
        vector<vector<int>> result;
        for(int i=1; i<intervals.size(); i++) {
            int currStart = intervals[i][0], currEnd = intervals[i][1];
            if(currStart<=end) {
                if(currEnd<=end) {
                    continue;
                }
                else {
                    end = currEnd;
                }
            }
            else {
                // push the previous start and end data
                vector<int> temp;
                temp.push_back(start);
                temp.push_back(end);
                result.push_back(temp);
                start = currStart;
                end = currEnd;
            }
        }
        vector<int> temp;
        temp.push_back(start);
        temp.push_back(end);
        result.push_back(temp);
        return result;
    }
};