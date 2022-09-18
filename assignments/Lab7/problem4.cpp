// https://leetcode.com/problems/word-break/

class Solution {
private:
    void solve(string& s, vector<string>& wordDict, int index, vector<bool>& dp) {
        for(int i=0; i<wordDict.size(); i++) {
            string currWord = s.substr(index, wordDict[i].size());
            if(wordDict[i]==currWord) {
                if(index+wordDict[i].size()==s.size()) dp[index]=true;
                else if(index+wordDict[i].size()<s.size() and dp[index+wordDict[i].size()]==true)
                    dp[index]=true;
            }
        }
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size(), false);
        for(int i=s.size()-1; i>=0; i--) {
            solve(s, wordDict, i, dp);   
        }
        return dp[0];
    }
};