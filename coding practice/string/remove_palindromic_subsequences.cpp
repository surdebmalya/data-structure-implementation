// https://leetcode.com/problems/remove-palindromic-subsequences/

// Easy

class Solution {
public:
    int removePalindromeSub(string s) {
        // answer will be 1 or 2
        // when 1?
        // well when the full string is palindrome itself
        // otherwise the answer will be 2

        // so first check whether the full string is palindrome or not?
        int n = s.size();
        for (int i = 0; i < n / 2; i++) {
            if (s[i] != s[n - 1 - i])
                return 2;
        }
        return 1;
    }
};