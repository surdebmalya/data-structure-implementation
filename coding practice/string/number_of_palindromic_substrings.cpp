// https://leetcode.com/problems/palindromic-substrings/

// Medium

class Solution {
public:
    int countSubstrings(string s) {
        int number = 0;
        for (int idx = 0; idx < s.size(); idx++) {
            // for odd lengths
            int i = idx, j = idx;
            while (i >= 0 and j < s.size() and s[i] == s[j]) {
                number++;
                i--;
                j++;
            }

            // for even lengths
            i = idx, j = idx + 1;
            while (i >= 0 and j < s.size() and s[i] == s[j]) {
                number++;
                i--;
                j++;
            }
        }
        return number;
    }
};