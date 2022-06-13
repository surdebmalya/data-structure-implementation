// https://leetcode.com/problems/next-greater-element-iii/

// Medium

class Solution {
public:
    int nextGreaterElement(int n) {
        // next permutation approach
        vector<int> digits;
        while (n) {
            digits.push_back(n % 10);
            n = n / 10;
        }
        reverse(digits.begin(), digits.end());

        if (next_permutation(digits.begin(), digits.end())) {
            long int result = 0;
            for (int i = 0; i < digits.size(); i++) {
                result = 10 * result + digits[i];
            }
            if (result > INT_MAX)
                return -1;
            return result;
        } else
            return -1;
    }
};