// https://leetcode.com/problems/string-matching-in-an-array/

class Solution {
public:
    bool static cmp(string a, string b) {
        if(a.size()<b.size()) return true;
        else return false;
    }
    vector<string> stringMatching(vector<string>& words) {
        sort(words.begin(), words.end(), cmp);
        unordered_set<string> result;
        for(int i=0; i<words.size(); i++) {
            for(int j=i+1; j<words.size(); j++) {
                if(words[j].find(words[i])!=-1) {
                    result.insert(words[i]);
                }
            }
        }
        vector<string> r;
        auto it=result.begin();
        while(it!=result.end()) {
            r.push_back(*it);
            it++;
        }
        return r;
    }
};