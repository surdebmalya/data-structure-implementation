// https://leetcode.com/problems/maximum-product-of-word-lengths/

// Medium

class Solution {
private:
    bool isCommon(bitset<26> &bs1, bitset<26> &bs2) {
        for (int i = 0; i < 26; i++) {
            if (bs1[i] and bs2[i])
                return true;
        }
        return false;
    }

public:
    int maxProduct(vector<string> &words) {
        int ans = 0;
        vector<bitset<26>> chars(words.size());
        for (int i = 0; i < words.size(); i++) {
            for (int j = 0; j < words[i].size(); j++)
                chars[i][words[i][j] - 'a'] = 1;
            for (int j = 0; j < i; j++) {
                if (!(isCommon(chars[i], chars[j]))) {
                    int temp = words[i].size() * words[j].size();
                    ans = max(ans, temp);
                }
            }
        }
        return ans;
    }
};