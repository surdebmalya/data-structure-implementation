// https://leetcode.com/problems/find-bottom-left-tree-value/

// Medium

class Solution {
public:
    int findBottomLeftValue(TreeNode *root) {
        // do the level order traversal
        int prevLvl = 0;
        queue<pair<TreeNode *, int>> q; // node_address, node_level
        TreeNode *leftMostNode = NULL;
        q.push({root, 1});
        while (!(q.empty())) {
            pair<TreeNode *, int> curr = q.front();
            q.pop();
            if (prevLvl != curr.second) {
                leftMostNode = curr.first;
                prevLvl = curr.second;
            }
            if (curr.first->left != NULL)
                q.push({curr.first->left, curr.second + 1});
            if (curr.first->right != NULL)
                q.push({curr.first->right, curr.second + 1});
        }
        return leftMostNode->val;
    }
};