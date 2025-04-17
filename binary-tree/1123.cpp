/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    pair<int, TreeNode*> LCA(TreeNode* root) {
        if (root == nullptr)
            return {0, nullptr};

        auto [left_max_depth, left_lca] = LCA(root->left);
        auto [right_max_depth, right_lca] = LCA(root->right);

        if (left_max_depth > right_max_depth)
            return {left_max_depth + 1, left_lca};
        if (left_max_depth < right_max_depth)
            return {right_max_depth + 1, right_lca};
            
        return {left_max_depth + 1, root};
    }

    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return LCA(root).second;
    }
};