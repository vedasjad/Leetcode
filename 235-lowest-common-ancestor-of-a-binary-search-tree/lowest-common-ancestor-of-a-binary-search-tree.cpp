/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    bool hasNode(TreeNode* root, TreeNode* node) {
        if (!root)
            return false;
        if (root == node)
            return true;
        return hasNode(root->left, node) || hasNode(root->right, node);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root)
            return NULL;
        if ((hasNode(root->left, p) || hasNode(root->right, p) || hasNode(root,p)) &&
            (hasNode(root->left, q) || hasNode(root->right, q) || hasNode(root,q))) {
            if (lowestCommonAncestor(root->left, p, q) == NULL &&
                lowestCommonAncestor(root->right, p, q) == NULL) {
                return root;
            } else {
                return lowestCommonAncestor(root->left, p, q)
                           ? lowestCommonAncestor(root->left, p, q)
                           : lowestCommonAncestor(root->right, p, q);
            }
        }
        return NULL;
    }
};