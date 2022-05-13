// https://leetcode.com/problems/longest-substring-without-repeating-characters/

// Medium

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // 2 pointers approach
        if (s.size() == 0) {
            return 0;
        }
        unordered_map<char, int> um;
        for (int index = 0; index < 26; index++) {
            um.insert(make_pair('a' + index, 0));
        }

        int startIndex = 0, endIndex = 0, result = 0, currLength = 0;
        while (endIndex < s.size()) {
            char currChar = s[endIndex];
            if (um[currChar] == 0) {
                currLength++;
                um[currChar] = 1;
                endIndex++;
                if (currLength > result) {
                    result = currLength;
                }
            } else {
                // increament the startIndex
                while (um[currChar] != 0) {
                    char startIndexChar = s[startIndex];
                    um[startIndexChar] = 0;
                    startIndex++;
                    currLength--;
                }
                um[currChar] = 1;
                currLength++;
                endIndex++;
                if (currLength > result) {
                    result = currLength;
                }
            }
        }
        return result;
    }
};