// https://leetcode.com/problems/decode-string/

// Medium

class Solution {
public:
    string decodeString(string str) {
        stack<int> si;
        stack<string> ss;
        int digit = 0;

        for (int index = 0; index < str.size(); index++) {
            if (str[index] >= '0' and str[index] <= '9') {
                int temp_num = str[index] - '0';
                digit = 10 * digit + temp_num;
            } else if (str[index] == '[') {
                si.push(digit);
                digit = 0;
                ss.push("[");
            } else if (str[index] >= 'a' and str[index] <= 'z') {
                string temp_string = "";
                temp_string += str[index];
                ss.push(temp_string);
            } else if (str[index] == ']') {
                string temp_string = "";
                while (ss.top() != "[") {
                    temp_string = ss.top() + temp_string;
                    ss.pop();
                }
                ss.pop();

                int itr = si.top();
                si.pop();
                string pushable_str = "";
                while (itr) {
                    pushable_str += temp_string;
                    itr--;
                }
                ss.push(pushable_str);
            }
        }
        if (si.empty()) {
            // only element in the ss stack
            string result = "";
            while (!(ss.empty())) {
                result = ss.top() + result;
                ss.pop();
            }
            return result;
        } else {
            string result = "";
            while (ss.top() != "[") {
                result = ss.top() + result;
                ss.pop();
            }
            int itr = si.top();
            while (itr) {
                result += result;
                itr--;
            }
            return result;
        }
    }
};