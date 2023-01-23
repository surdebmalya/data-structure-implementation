class Solution {
public:
    bool solve(vector<vector<int>>& nums, int n, int curr_judge) {
        int count=0;
        for(int i=0; i<nums.size(); i++) {
            if(nums[i][1]==curr_judge) count++;
        }
        if(count==n-1) return true;
        return false;
    }
    int findJudge(int n, vector<vector<int>>& nums) {
        if(n==1 and nums.size()==0) return 1;
        unordered_set<int> us1, us2;
        for(int i=0; i<nums.size(); i++) {
            us1.insert(nums[i][0]);
            us2.insert(nums[i][1]);
        }
        auto it = us2.begin();
        while(it!=us2.end()) {
            int curr_judge = *it;
            if(us1.find(curr_judge)==us1.end()) {
                if(solve(nums, n, curr_judge)) return curr_judge;
            }
            it++;
        }
        return -1;
    }
};