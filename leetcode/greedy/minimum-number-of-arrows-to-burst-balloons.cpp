class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int arrows=1;
        int start=points[0][0], end=points[0][1];
        for(int i=1; i<points.size(); i++) {
            if(points[i][0]<=end) {
                start = points[i][0];
                if(points[i][1]<end) end = points[i][1];
            }
            else {
                arrows++;
                start = points[i][0];
                end = points[i][1];
            }
        }
        return arrows;
    }
};