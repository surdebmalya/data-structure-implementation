class Solution {
public:
    int solve(vector<vector<int>>& points, int x1, int y1, int x2, int y2) {
        int count = 0;
        for(int i=0; i<points.size(); i++) {
            int currX = points[i][0], currY = points[i][1];
            if((currY-y1)*(x2-x1)==(currX-x1)*(y2-y1)) count++;
        }
        return count;
    }
    int maxPoints(vector<vector<int>>& points) {
        if(points.size()==1) return 1;
        int res = 2;
        for(int i=0; i<=points.size()-2; i++) {
            int x1 = points[i][0], y1 = points[i][1];
            for(int j=i+1; j<points.size(); j++) {
                int x2 = points[j][0], y2 = points[j][1];
                int temp = solve(points, x1, y1, x2, y2);
                res = max(res, temp);
            }
        }
        return res;
    }
};