class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        map<int, vector<int>> mp;
        for(int i=0; i<groupSizes.size(); i++) {
            if(mp.find(groupSizes[i])==mp.end()) {
                // the element is not present
                vector<int> temp;
                temp.push_back(i);
                mp[groupSizes[i]] = temp;
            }
            else {
                // the element is present
                mp[groupSizes[i]].push_back(i);
            }
        }
        vector<vector<int>> result;
        auto it = mp.begin();
        while(it!=mp.end()) {
            int length = it->first;
            vector<int> arr = it->second;
            for(int i=0; i<arr.size(); i++) {
                int n = length;
                vector<int> tempArr;
                while(n--) {
                    tempArr.push_back(arr[i]);
                    i++;
                }
                result.push_back(tempArr);
                i--;
            }
            it++;
        }
        return result;
    }
};