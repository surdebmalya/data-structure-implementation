// https://codingcompetitions.withgoogle.com/kickstart/round/00000000008cb33e/00000000009e7021

#include<bits/stdc++.h>
using namespace std;

int main() {
    // taking input
    int t=1;
    cin>>t;
    int flag=1;
    while(t--) {
        cout << "Case #" << flag << ": ";
        string s, p;
        cin>>s>>p;
        
        int i=0, j=0;
        int n=s.size(), m=p.size();
        while(i<n and j<m) {
            if(s[i]==p[j]) {
                i++; j++;
            }
            else {
                j++;
            }
        }
        if(i==n) {
            cout<<m-n<<endl;
        }
        else {
            cout <<"IMPOSSIBLE"<<endl;
        }
        
        flag++;
    }
    
    return 0;
}