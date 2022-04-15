// https://practice.geeksforgeeks.org/problems/array-to-bst4443/1

// Easy

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    struct Node {
        int data;
        struct Node *left, *right;
    };

    struct Node *make_tree(vector<int> &nums, int start, int end) {
        if (start <= end) {
            int mid = (start + end) / 2;
            struct Node *temp = new Node();
            temp->data = nums[mid];
            temp->left = make_tree(nums, start, mid - 1);
            temp->right = make_tree(nums, mid + 1, end);
            return temp;
        } else {
            return NULL;
        }
    }

    void preorder(struct Node *root, vector<int> &result) {
        if (root == NULL) {
            return;
        }
        result.push_back(root->data);
        preorder(root->left, result);
        preorder(root->right, result);
    }

    vector<int> sortedArrayToBST(vector<int> &nums) {
        int size = nums.size();
        // make tree
        int start = 0;
        int end = size - 1;
        auto root = make_tree(nums, start, end);

        vector<int> result;
        preorder(root, result);
        return result;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++)
            cin >> nums[i];
        Solution obj;
        vector<int> ans = obj.sortedArrayToBST(nums);
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
} // } Driver Code Ends