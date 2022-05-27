// https://leetcode.com/problems/number-of-steps-to-reduce-a-number-to-zero/

// Easy

class Solution {
public:
    int numberOfSteps(int num) {
        int result = 0;
        while (num) {
            result++;
            if (num % 2)
                num--;
            else
                num /= 2;
        }
        return result;
    }
};