// https://practice.geeksforgeeks.org/problems/validate-an-ip-address-1587115621/1

// Medium

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/* The function returns 1 if
IP string is valid else return 0
You are required to complete this method */
class Solution {
    private:
        bool valid(string octet) {
            // checking whether excess 0s or not?
            int temp1 = stoi(octet);
            string temp2 = to_string(temp1);
            if (octet.size()!=temp2.size()) {
                return false;
            }
            else {
                if (temp1>=0 and temp1<=255) {
                    return true;
                }
                return false;
            }
        }
    public:
        int isValid(string s) {
            int dots=0;
            auto it = s.begin();
            string mod_str = "";
            while (it!=s.end()) {
                if ((*it >= '0' and *it<='9') or *it=='.') {
                    if (*it=='.') {
                        mod_str += " ";
                        dots++;
                    }
                    else {
                        mod_str += *it;
                    }
                }
                else {
                    return 0;
                }
                it++;
            }
            if (dots!=3) {
                return 0;
            }
            else {
                stringstream ss(mod_str);
                string word;
                int count = 0;
                while (ss>>word) {
                    count++;
                    if (!valid(word)) {
                        return 0;
                    }
                }
                if (count==4)
                    return 1;
                return 0;
            }
        }
};

// { Driver Code Starts.

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.isValid(s) << endl;
    }
    return 0;
}  // } Driver Code Ends