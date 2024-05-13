/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int goodNodes(TreeNode* root, int mx = INT_MIN) {
        if (!root)
            return 0;
        int count = 0;
        if (root->val >= mx)
            count++;
        if (root->left)
            count += goodNodes(root->left, max(mx, root->val));
        if (root->right)
            count += goodNodes(root->right, max(mx, root->val));
        return count;
    }
};