// https://practice.geeksforgeeks.org/problems/find-duplicates-in-an-array/1/

// Easy

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    vector<int> duplicates(int arr[], int n) {
        unordered_set<int> s;
        int outside = n;
        for (int i = 0; i < n; i++) {
            if (abs(arr[i]) == outside) {
                if (arr[0] == 0)
                    arr[0] = -outside;
                else if (arr[0] < 0)
                    s.insert(0);
                else
                    arr[0] = -arr[0];
            } else {
                if (arr[abs(arr[i])] == 0)
                    arr[abs(arr[i])] = -outside;
                else if (arr[abs(arr[i])] < 0)
                    s.insert(abs(arr[i]));
                else
                    arr[abs(arr[i])] = -arr[abs(arr[i])];
            }
        }
        vector<int> result;
        if (s.size() == 0)
            return {-1};
        auto it = s.begin();
        while (it != s.end()) {
            result.push_back(*it);
            it++;
        }
        sort(result.begin(), result.end());
        return result;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        Solution obj;
        vector<int> ans = obj.duplicates(a, n);
        for (int i : ans)
            cout << i << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends