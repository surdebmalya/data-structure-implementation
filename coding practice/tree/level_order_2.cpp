// https://leetcode.com/problems/binary-tree-level-order-traversal/

// Medium

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode *root) {
        vector<vector<int>> result;
        if (root == NULL)
            return result;

        int prevLevel = 0;
        queue<pair<TreeNode *, int>> q;
        q.push({root, 1});
        vector<int> tempStorage = {root->val};
        while (!(q.empty())) {
            pair<TreeNode *, int> curr = q.front();
            q.pop();
            if (curr.second != prevLevel) {
                result.push_back(tempStorage);
                tempStorage = {};
                tempStorage.push_back(curr.first->val);
                prevLevel = curr.second;
                if (curr.first->left != NULL)
                    q.push({curr.first->left, curr.second + 1});
                if (curr.first->right != NULL)
                    q.push({curr.first->right, curr.second + 1});
            } else {
                tempStorage.push_back(curr.first->val);
                if (curr.first->left != NULL)
                    q.push({curr.first->left, curr.second + 1});
                if (curr.first->right != NULL)
                    q.push({curr.first->right, curr.second + 1});
            }
        }
        result.push_back(tempStorage);
        result.erase(result.begin());
        return result;
    }
};