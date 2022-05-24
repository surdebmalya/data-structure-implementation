// https://leetcode.com/problems/binary-tree-paths/

// Easy

class Solution {
private:
    vector<string> result;
    string arrToString(vector<int> &arr) {
        string result = "";
        for (int i = 0; i < arr.size() - 1; i++) {
            result += to_string(arr[i]) + "->";
        }
        result += to_string(arr[arr.size() - 1]);
        return result;
    }
    void f(TreeNode *root, vector<int> &arr) {
        if (root->left == NULL and root->right == NULL) {
            result.push_back(arrToString(arr));
            return;
        }
        if (root->left != NULL) {
            vector<int> temp = arr;
            temp.push_back(root->left->val);
            f(root->left, temp);
        }
        if (root->right != NULL) {
            vector<int> temp = arr;
            temp.push_back(root->right->val);
            f(root->right, temp);
        }
    }

public:
    vector<string> binaryTreePaths(TreeNode *root) {
        if (root->left == NULL and root->right == NULL) {
            result.push_back(to_string(root->val));
            return result;
        }
        vector<int> arr = {root->val};
        f(root, arr);
        return result;
    }
};