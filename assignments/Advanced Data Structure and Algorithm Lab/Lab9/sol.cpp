#include <bits/stdc++.h>
using namespace std;

int naive(string text, string pattern) {
    // time: O(m*n)
    int n=text.size(), m=pattern.size();
    for(int i=0; i<=n-m; i++) {
        bool flag=false;
        int starting = i;
        for(int j=0; j<m; j++) {
            if(text[i]!=pattern[j]) {
                flag=true;
                break;
            }
            i++;
        }
        if(flag==false) return starting;
        i=starting;
    }
    return -1;
}

vector<int> LPSArray(string pat) {
    int m=pat.size();
    vector<int> lps(m, 0);
    int len=0;
    lps[0]=0;
    int i=1;
    while(i<m) {
        if(pat[i]==pat[len]) {
            len++;
            lps[i]=len;
            i++;
        }
        else {
            if(len!=0) {
                len=lps[len-1];
            }
            else {
                lps[i]=0;
                i++;
            }
        }
    }
    lps.insert(lps.begin(), -1);
    return lps;
}

int kmp(string text, string pattern) {
    // time: O(m+n)
    int n=text.size(), m=pattern.size();
    vector<int> lps = LPSArray(pattern);
    // printing the LPS array
    for(int i=0; i<lps.size(); i++) {
        cout << lps[i] << " ";
    }
    cout << endl;
    pattern = "#"+pattern;
    int i=0, j=0;
    while(i<n) {
        if(pattern[j+1]==text[i]) {
            i++;
            j++;
            if(j==m) return i-m;
        }
        else {
            // the characters are not matching
            if(j==0) {
                i++;
            }
            else {
                j=lps[j];
            }
        }
    }
    return -1;
}

int finite(string text, string pattern) {
    
}

int main() {
    string text, pattern;
    // cin >> text >> pattern;
    text = "abbcaabbcd";
    pattern = "aabb";
    
    cout << naive(text, pattern) << endl;
    cout << kmp(text, pattern) << endl;
    cout << finite(text, pattern) << endl;

    return 0;
}