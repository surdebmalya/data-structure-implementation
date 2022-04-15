// https://practice.geeksforgeeks.org/problems/maximum-sum-rectangle2948/1#

// Medium

// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
private:
    int kadane(vector<int> &arr) {
        int max = arr[0];
        int curr_sum = arr[0];
        for (int index = 1; index < arr.size(); index++) {
            curr_sum = (curr_sum + arr[index]) > arr[index] ? curr_sum + arr[index] : arr[index];
            max = curr_sum > max ? curr_sum : max;
        }
        return max;
    }

public:
    int maximumSumRectangle(int R, int C, vector<vector<int>> M) {
        int result = INT_MIN;
        for (int left = 0; left < R; left++) {
            vector<int> temp(C, 0);
            for (int right = left; right < R; right++) {
                for (int col = 0; col < C; col++) {
                    temp[col] += M[right][col];
                }
                int max_sum = kadane(temp);
                result = (max_sum > result) ? max_sum : result;
            }
        }
        return result;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                cin >> v[i][j];
        Solution ob;
        cout << ob.maximumSumRectangle(N, M, v) << "\n";
    }
} // } Driver Code Ends