// Implementing Hill cipher

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> solve(vector<vector<int>>& key, vector<vector<int>>& currVector) {
    vector<vector<int>> result;
    for(int i=0; i<key.size(); i++) {
        int val=0;
        for(int j=0; j<key[0].size(); j++) {
            val += key[i][j]*currVector[j][0];
        }
        vector<int> temp;
        temp.push_back(val % 26);
        result.push_back(temp);
    }
    return result;
}

int main() {
    string cipherText = "YITJPGWJOWFAQTQXCSMAETSQUSQAPUSQGKCPQTYJ";
    // given the inverse key
    vector<vector<int>> key = {
        {5, 1},
        {2, 7}
    };
    
    int N = key.size();
    for(int i=0; i<cipherText.size(); i++) {
        string currString;
        int n = N;
        while(n--) {
            currString += cipherText[i];
            i++;
        }
        i--;
        
        // making the matrix corresponding to the current string
        vector<vector<int>> tempVector;
        for(int j=0; j<currString.size(); j++) {
            vector<int> temp;
            temp.push_back(currString[j] - 'A');
            tempVector.push_back(temp);
        }
        
        vector<vector<int>> actualMatrix = solve(key, tempVector);
        string actualString;
        for(int j=0; j<actualMatrix.size(); j++) {
            actualString += ('A' + actualMatrix[j][0]);
        }
        
        cout << actualString;
    }

    return 0;
}
