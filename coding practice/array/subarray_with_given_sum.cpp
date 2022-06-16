// https://practice.geeksforgeeks.org/problems/subarray-with-given-sum-1587115621/1/

// Easy

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    // Time: O(n) and Space: O(1).
    vector<int> subarraySum(int arr[], int n, long long s) {
        long long sum = 0;
        int start = 0, end = 0, flag = 0;
        for (int i = 0; i < n; i++) {
            sum += arr[i];
            while (sum > s && start < i) {
                sum -= arr[start];
                start++;
            }
            if (sum == s) {
                end = i;
                flag = 1;
                break;
            }
        }
        if (start > end || flag == 0)
            return {-1};
        return {start + 1, end + 1};
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        long long s;
        cin >> n >> s;
        int arr[n];
        const int mx = 1e9;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        vector<int> res;
        res = ob.subarraySum(arr, n, s);

        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
    }
    return 0;
} // } Driver Code Ends