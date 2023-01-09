// https://leetcode.com/problems/boats-to-save-people/

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        multiset<int> ms;
        int ans=0;
        for(int i=0; i<people.size(); i++) ms.insert(people[i]);
        while(ms.size()!=0) {
            int curr = *(ms.begin());
            auto it = ms.begin();
            ms.erase(ms.lower_bound(curr));
            int another = limit - curr;
            for(int i=another; i>=1; i--) {
                if(ms.find(i)!=ms.end()) {
                    ms.erase(ms.lower_bound(i));
                    break;
                }
            }
            ans++;
        }
        return ans;
    }
};