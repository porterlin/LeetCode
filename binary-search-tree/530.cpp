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
    int pre = INT_MAX;
    int ans = INT_MAX;
    int getMinimumDifference(TreeNode* root) {
        if (root == nullptr)
            return INT_MAX;
        
        getMinimumDifference(root->left);
        
        ans = min(ans, abs(pre - root->val));
        pre = root->val;

        getMinimumDifference(root->right);
        return ans;
    }
};