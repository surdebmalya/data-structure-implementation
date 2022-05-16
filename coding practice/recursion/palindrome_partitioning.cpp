// https://leetcode.com/problems/palindrome-partitioning/

// Medium

class Solution {
    bool checkPalindrome(string s) {
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != s[s.size() - 1 - i])
                return false;
        }
        return true;
    }
    void solve(string s, vector<string> &currArr, vector<vector<string>> &result, int index, int lastPartition) {
        if (index == s.size() - 1) {
            string sstr = s.substr(lastPartition, index - lastPartition + 1);
            if (checkPalindrome(sstr)) {
                currArr.push_back(sstr);
                result.push_back(currArr);
                currArr.pop_back();
            }
            return;
        }
        string sstr = s.substr(lastPartition, index - lastPartition + 1);
        if (checkPalindrome(sstr)) {
            currArr.push_back(sstr);
            solve(s, currArr, result, index + 1, index + 1);
            currArr.pop_back();
        }
        solve(s, currArr, result, index + 1, lastPartition);
    }

public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        if (s.size() == 1) {
            result.push_back({s});
            return result;
        }
        vector<string> currArr;
        solve(s, currArr, result, 0, 0);
        return result;
    }
};