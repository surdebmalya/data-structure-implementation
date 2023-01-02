class Solution {
public:
    string longestPalindrome(string s) {
        int result=INT_MIN;
        string str;
        // odd length substring finding
        for(int i=0; i<s.size(); i++) {
            int start=i, end=i;
            while(start>=0 and end<s.size()) {
                if(s[start]!=s[end]) break;
                else {
                    if(result < end-start+1) {
                        str = s.substr(start, end-start+1);
                        result = end-start+1;
                    }
                    start--; end++;
                }
            }
            
            // even length substring finding
            start=i; end=i+1;
            while(start>=0 and end<s.size()) {
                if(s[start]!=s[end]) break;
                else {
                    if(result < end-start+1) {
                        str = s.substr(start, end-start+1);
                        result = end-start+1;
                    }
                    start--; end++;
                }
            }
        }
        
        return str;
    }
};