// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/

// Medium

class Solution {
public:
    string removeDuplicates(string str, int k) {
        stack<pair<char, int>> st;
        for (int index = 0; index<str.size(); index++) {
            char curr_char = str[index];
            if (st.empty()) {
                st.push(make_pair(curr_char, 1));
            }
            else {
                auto curr_top = st.top();
                if (curr_char==curr_top.first) {
                    if (curr_top.second==k) {
                        st.pop();
                        st.push(make_pair(curr_char, 1));
                    }
                    else {
                        st.top().second += 1;
                        if (st.top().second==k) {
                            st.pop();
                        }
                    }
                }
                else {
                    st.push(make_pair(curr_char, 1));
                }
            }
        }
        string result = "";
        while (!(st.empty())) {
            auto temp_top = st.top();
            st.pop();
            int itr = temp_top.second;
            string temp_string = "";
            while (itr) {
                temp_string += temp_top.first;
                itr--;
            }
            result = temp_string + result;
        }
        return result;
    }
};