class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        vector<vector<int>> times;
        for(int i=0; i<plantTime.size(); i++) {
            vector<int> temp;
            temp.push_back(growTime[i]);
            temp.push_back(plantTime[i]);
            times.push_back(temp);
        }
        sort(times.begin(), times.end());
        int starting=0, ending=0;
        for(int i=times.size()-1; i>=0; i--) {
            int tempEnd = starting + times[i][0] + times[i][1];
            ending = max(ending, tempEnd);
            starting += times[i][1];
        }
        return ending;
    }
};