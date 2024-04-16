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
    TreeNode* addOneRow(TreeNode* root, int val, int depth,
                        int currentDepth = 1) {
        if (depth == 1 || !root) {
            TreeNode* newNode = new TreeNode(val);
            newNode->left = root;
            return newNode;
        }
        if (depth - 1 == currentDepth) {
            TreeNode *newNode1 = new TreeNode(val),
                     *newNode2 = new TreeNode(val);
            newNode1->left = root->left;
            root->left = newNode1;
            newNode2->right = root->right;
            root->right = newNode2;
            return root;
        }
        addOneRow(root->left, val, depth, currentDepth + 1);
        addOneRow(root->right, val, depth, currentDepth + 1);
        return root;
    }
};