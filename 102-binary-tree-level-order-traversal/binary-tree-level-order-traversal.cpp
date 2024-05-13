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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root)
            return res;

        queue<TreeNode*> lvl;
        lvl.push(root);
        while (!lvl.empty()) {
            int size = lvl.size();
            vector<int> currLvl;
            for (int i = 0; i < size; i++) {
                TreeNode* frnt = lvl.front();
                lvl.pop();
                currLvl.push_back(frnt->val);
                if (frnt->left)
                    lvl.push(frnt->left);
                if (frnt->right)
                    lvl.push(frnt->right);
            }
            res.push_back(currLvl);
        }
        return res;
    }
};