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
    void dfs(TreeNode* root1, TreeNode* root2, TreeNode* mergedTree) {
        if (root1 == root2)
            return;

        if ((root1 && root1->left) || (root2 && root2->left))
            mergedTree->left = new TreeNode();
        if ((root1 && root1->right) || (root2 && root2->right))
            mergedTree->right = new TreeNode();
        
        if (root1 && root2) {
            mergedTree->val = root1->val + root2->val;
            dfs(root1->left, root2->left, mergedTree->left);
            dfs(root1->right, root2->right, mergedTree->right);
        } else if (root1 && !root2) {
            mergedTree->val = root1->val;
            dfs(root1->left, root2, mergedTree->left);
            dfs(root1->right, root2, mergedTree->right);
        } else {
            mergedTree->val = root2->val;
            dfs(root1, root2->left, mergedTree->left);
            dfs(root1, root2->right, mergedTree->right);
        }

        return;
    }

    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (root1 == root2)
            return nullptr;
        TreeNode* mergedTree = new TreeNode();
        dfs(root1, root2, mergedTree);
        return mergedTree;
    }
};