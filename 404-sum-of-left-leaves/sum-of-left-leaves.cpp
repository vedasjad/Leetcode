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
    int goInorder(struct TreeNode* node, int sum) {
        if (node == NULL)
            return 0;
        int left = 0;
        if (node->left != NULL) {
            if (node->left->left == NULL && node->left->right == NULL)
                left = node->left->val;
            left += goInorder(node->left, sum);
        }
        int right = goInorder(node->right, sum);
        return left + right;
    }

    int sumOfLeftLeaves(TreeNode* root) { return goInorder(root, 0); }
};