class Solution {
public:
    set<vector<int>> result;
    void solve(vector<int>& nums, int index, vector<int>& temp) {
        if(index==nums.size()) {
            if(temp.size()>=2)
                result.insert(temp);
            return;
        }
        else {
            if(temp.size()==0) {
                // take
                temp.push_back(nums[index]);
                solve(nums, index+1, temp);
                temp.pop_back();

                // skip
                solve(nums, index+1, temp);
            }
            else {
                if(nums[index]>=temp[temp.size()-1]) {
                    // take
                    temp.push_back(nums[index]);
                    solve(nums, index+1, temp);
                    temp.pop_back();

                    // skip
                    solve(nums, index+1, temp);
                }
                else {
                    // skip
                    solve(nums, index+1, temp);
                }
            }
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> temp;
        solve(nums, 0, temp);
        vector<vector<int>> res;
        auto it = result.begin();
        while(it!=result.end()) {
            res.push_back(*it);
            it++;
        }
        return res;
    }
};