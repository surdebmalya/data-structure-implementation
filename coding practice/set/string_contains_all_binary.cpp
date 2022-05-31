// https://leetcode.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k/

// Medium

class Solution {
private:
    string toBinary(int num, int max) {
        string temp = "";
        while (num) {
            temp = to_string(num % 2) + temp;
            num /= 2;
        }

        int diff = max - temp.size();
        string extra = "";
        while (diff) {
            extra += '0';
            diff--;
        }

        return extra + temp;
    }

public:
    bool hasAllCodes(string s, int k) {
        if (k >= s.size())
            return false;

        unordered_set<string> us;
        for (int i = 0; i < s.size() - k + 1; i++) {
            string curr = s.substr(i, k);
            us.insert(curr);
        }

        for (int i = 0; i <= pow(2, k) - 1; i++) {
            string temp = toBinary(i, k);
            if (us.find(temp) == us.end())
                return false;
        }
        return true;
    }
};