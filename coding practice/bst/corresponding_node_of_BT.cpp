// https://leetcode.com/problems/find-a-corresponding-node-of-a-binary-tree-in-a-clone-of-that-tree/

// Medium

class Solution {
public:
    TreeNode *getTargetCopy(TreeNode *original, TreeNode *cloned, TreeNode *target) {
        if (original == target) {
            return cloned;
        }
        if (original == NULL and original == NULL) {
            return NULL;
        }
        TreeNode *l = getTargetCopy(original->left, cloned->left, target);
        TreeNode *r = getTargetCopy(original->right, cloned->right, target);
        if (l != NULL)
            return l;
        if (r != NULL)
            return r;
        return NULL;
    }
};