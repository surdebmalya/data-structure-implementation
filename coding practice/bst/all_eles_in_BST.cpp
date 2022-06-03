// https://leetcode.com/problems/all-elements-in-two-binary-search-trees/

// Medium

class Solution {
private:
    void inorderTraversal(TreeNode *root, vector<int> &arr) {
        if (root == NULL)
            return;
        inorderTraversal(root->left, arr);
        arr.push_back(root->val);
        inorderTraversal(root->right, arr);
    }

public:
    vector<int> getAllElements(TreeNode *root1, TreeNode *root2) {
        vector<int> arr1, arr2;
        inorderTraversal(root1, arr1);
        inorderTraversal(root2, arr2);

        vector<int> result;
        int index1 = 0, index2 = 0;
        while (index1 != arr1.size() and index2 != arr2.size()) {
            if (arr1[index1] < arr2[index2]) {
                result.push_back(arr1[index1]);
                index1++;
            } else {
                result.push_back(arr2[index2]);
                index2++;
            }
        }
        if (index1 == arr1.size()) {
            for (int i = index2; i < arr2.size(); i++)
                result.push_back(arr2[i]);
        } else {
            for (int i = index1; i < arr1.size(); i++)
                result.push_back(arr1[i]);
        }
        return result;
    }
};