class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int count=0;
        for(int j=0; j<strs[0].size(); j++) {
            int prev = INT_MIN;
            bool flag=true;
            for(int i=0; i<strs.size(); i++) {
                if(strs[i][j]>=prev) prev = strs[i][j];
                else {
                    flag=false;
                    break;
                }
            }
            if(flag==false) count++;
        }
        return count;
    }
};