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
    string smallestFromLeaf(TreeNode* root, string prevStr = "") {
        if (!root) {
            return prevStr;
        }
        char currChar = int('a') + root->val;
        if (root->left && root->right) {
            return min(smallestFromLeaf(root->left, currChar + prevStr),
                       smallestFromLeaf(root->right, currChar + prevStr));
        }
        if (!root->left) {
            return smallestFromLeaf(root->right, currChar + prevStr);
        }
        if (!root->right) {
            return smallestFromLeaf(root->left, currChar + prevStr);
        }
        return currChar + prevStr;
    }
};