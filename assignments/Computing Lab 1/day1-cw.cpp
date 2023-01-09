// Implementing ceaser cipher

#include <bits/stdc++.h>
using namespace std;

#define a 3
#define b 5
#define gram 2

int modInverse(int A, int M) {
    for (int X = 1; X < M; X++)
        if (((A % M) * (X % M)) % M == 1)
            return X;
    return -1;
}

int main() {
    string str;
    cout << "Enter the string: ";
    cin >> str;
    
    int N = pow(26, gram);
    
    for(int currIndex=str.size()-1; currIndex>=0; currIndex--) {
        int tempGram = gram;
        string currStr;
        while(tempGram--) {
            currStr += str[currIndex];
            currIndex--;
            if(currIndex<0) break;
        }
        currIndex++;
        reverse(currStr.begin(), currStr.end());
        
        // finding out the plaintext value
        int sum=0;
        int suff=0;
        for(int i=currStr.size()-1; i>=0; i--) {
            sum += (currStr[i] - 'A') * pow(26, suff);
            suff++;
        }
        
        // fining the cipher text value
        int c = (a * sum + b) % N;
        int value_c = c;
        
        // converting the cipher text
        string cText;
        while(c) {
            char ch;
            int rem = c % 26;
            c = c/26;
            ch = 'A' + rem;
            cText.push_back(ch);
        }
        reverse(cText.begin(), cText.end());
        cout << "The chiper text is: " << cText << endl;
        
        // inverting
        int a_inv = modInverse(a, N);
        int back = (a_inv * (value_c - b)) % N;
        
        // converting to the actual value
        string actualText;
        if(back==0) {
            actualText="A";
        }
        while(back) {
            char ch;
            int rem = back % 26;
            back = back/26;
            ch = 'A' + rem;
            actualText.push_back(ch);
        }
        reverse(actualText.begin(), actualText.end());
        cout << "The actual text is: " << actualText << endl;
    }
    
    return 0;
}