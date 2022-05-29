// https://leetcode.com/problems/add-binary/

// Easy

class Solution {
private:
    string matchingZeros(string str, int n) {
        for (int i = 0; i < n; i++) {
            str = '0' + str;
        }
        return str;
    }

    string addition(string a, string b) {
        char carry = '0';
        string result = "";
        for (int i = a.size() - 1; i >= 0; i--) {
            if (carry == '0') {
                if (a[i] == '0' and b[i] == '0')
                    result = '0' + result;
                else if ((a[i] == '0' and b[i] == '1') or (a[i] == '1' and b[i] == '0'))
                    result = '1' + result;
                else {
                    carry = '1';
                    result = '0' + result;
                }
            } else { // carry=='1'
                if (a[i] == '0' and b[i] == '0') {
                    carry = '0';
                    result = '1' + result;
                } else if ((a[i] == '0' and b[i] == '1') or (a[i] == '1' and b[i] == '0')) {
                    carry = '1';
                    result = '0' + result;
                } else {
                    result = '1' + result;
                }
            }
        }
        if (carry == '1')
            result = '1' + result;
        return result;
    }

public:
    string addBinary(string a, string b) {
        string first = a, second = b;
        if (a.size() > b.size()) {
            first = a;
            second = matchingZeros(b, a.size() - b.size());
        } else if (a.size() < b.size()) {
            first = b;
            second = matchingZeros(a, b.size() - a.size());
        }

        return addition(first, second);
    }
};