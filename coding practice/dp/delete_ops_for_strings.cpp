// https://leetcode.com/problems/delete-operation-for-two-strings/

// Medium

class Solution {
private:
    int LCS(string word1, string word2, int index1, int index2, vector<vector<int>> &dp) {
        if (index1 < 0 or index2 < 0)
            return 0;
        if (dp[index1][index2] != -1)
            return dp[index1][index2];
        if (word1[index1] == word2[index2]) {
            return dp[index1][index2] = 1 + LCS(word1, word2, index1 - 1, index2 - 1, dp);
        } else {
            int skip1 = LCS(word1, word2, index1 - 1, index2, dp);
            int skip2 = LCS(word1, word2, index1, index2 - 1, dp);
            return dp[index1][index2] = max(skip1, skip2);
        }
    }

public:
    int minDistance(string word1, string word2) {
        // finding longest common subsequence
        int l1 = word1.size(), l2 = word2.size();
        vector<vector<int>> dp(l1, vector<int>(l2, -1));
        int common = LCS(word1, word2, l1 - 1, l2 - 1, dp);

        return max(l1 - common, l2 - common) + min(l1 - common, l2 - common);
    }
};