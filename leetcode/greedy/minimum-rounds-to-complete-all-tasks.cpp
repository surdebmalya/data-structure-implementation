class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int, int> mp; // element, freq
        for(int i=0; i<tasks.size(); i++) {
            mp[tasks[i]]++;
        }

        int res = 0;
        auto it = mp.begin();
        while(it!=mp.end()) {
            int currFreq = it->second;
            if(currFreq==1) return -1;
            else {
                int tempDays;
                if(currFreq%3==0) {
                    tempDays = currFreq/3;
                }
                else {
                    tempDays = (currFreq/3) + 1;
                }
                res += tempDays;
            }
            it++;
        }
        return res;
    }
};