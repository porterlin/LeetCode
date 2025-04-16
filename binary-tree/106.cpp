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
    unordered_map<int, int> mp;
    TreeNode* dfs(vector<int>& inorder, vector<int>& postorder, int inLeft, int inRight, int postLeft, int postRight) {
        if (postLeft > postRight)
            return nullptr;

        int rootIndex = mp[postorder[postRight]];

        TreeNode* root = new TreeNode(postorder[postRight]);
        root->left = dfs(inorder, postorder, inLeft, rootIndex - 1, postLeft, postLeft + rootIndex - inLeft - 1);
        root->right = dfs(inorder, postorder, rootIndex + 1, inRight, postLeft + rootIndex - inLeft, postRight - 1);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for (int i = 0; i < inorder.size(); i++)
            mp[inorder[i]] = i;

        return dfs(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
    }
};