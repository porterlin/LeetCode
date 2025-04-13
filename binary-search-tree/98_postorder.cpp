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
    pair<long long, long long> traversal(TreeNode* root) {
        if (!root)
            return {LLONG_MAX, LLONG_MIN};
        
        auto [l_min, l_max] = traversal(root->left);
        auto [r_min, r_max] = traversal(root->right);

        long long x = root->val;

        if (x <= l_max || x >= r_min)
            return {LLONG_MIN, LLONG_MAX};

        return {min(l_min, x), max(r_max, x)};
    }

    bool isValidBST(TreeNode* root) {
        auto [left, right] = traversal(root);
        return right != LLONG_MAX;
    }
};