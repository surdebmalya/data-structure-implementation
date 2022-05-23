// https://leetcode.com/problems/ones-and-zeroes/

// Medium

class Solution {
private:
    int dp[601][101][101];
    pair<int, int> count01(string str) {
        // returns <number_of_0s, number_of_1s>
        int count0 = 0, count1 = 0;
        for (int i = 0; i < str.size(); i++) {
            if (str[i] == '0')
                count0++;
            else
                count1++;
        }
        return make_pair(count0, count1);
    }
    int f(vector<string> &strs, int m, int n, int index) {
        if ((m < 0 or n < 0) or index < 0)
            return 0;
        if (dp[index][m][n] != -1)
            return dp[index][m][n];
        pair<int, int> zerosAndones = count01(strs[index]);
        int zeros = zerosAndones.first;
        int ones = zerosAndones.second;
        // take
        int take = 0, skip = 0;
        if (m - zeros >= 0 and n - ones >= 0) {
            take = 1 + f(strs, m - zeros, n - ones, index - 1);
        }
        // skip
        skip = f(strs, m, n, index - 1);
        return dp[index][m][n] = max(take, skip);
    }

public:
    int findMaxForm(vector<string> &strs, int m, int n) {
        // memoization technique
        memset(dp, -1, sizeof(dp));
        return f(strs, m, n, strs.size() - 1);
    }
};