class Solution {
public:
    int solve(vector<int> times, int last) {
        int res=0;
        for(int i=0; i<last; i++) {
            res += times[i];
        }
        return res;
    }
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int all_m=0, last_m=0, all_p=0, last_p=0, all_g=0, last_g=0;
        for(int i=0; i<garbage.size(); i++) {
            string currStr = garbage[i];
            for(int j=0; j<currStr.size(); j++) {
                if(currStr[j]=='M') {
                    all_m++;
                    last_m = i;
                }
                else if(currStr[j]=='P') {
                    all_p++;
                    last_p = i;
                }
                else {
                    all_g++;
                    last_g = i;
                }
            }
        }

        int res=0;
        res = solve(travel, last_m) + solve(travel, last_p) + solve(travel, last_g) + all_m + all_p + all_g;
        return res;
    }
};