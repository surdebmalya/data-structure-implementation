class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> um;
        int sum=0;
        for(int i=0; i<nums.size(); i++) {
            sum = (((sum + nums[i]) % k) + k) % k;
            um[sum]++;
        }
        int res = 0;
        auto it = um.begin();
        while(it!=um.end()) {
            if(it->first==0) {
                if(it->second>=2) {
                    int temp = it->second;
                    res = res + temp*(temp-1)/2 + temp;
                }
                else {
                    res += it->second;
                }
            }
            else {
                if(it->second>=2) {
                    int temp = it->second;
                    res = res + temp*(temp-1)/2;
                }
            }
            it++;
        }
        return res;
    }
};