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
    TreeNode* dfs(vector<int>& preorder, vector<int>& inorder, int preLeft, int preRight, int inLeft, int inRight) {
        if (preLeft > preRight)
            return nullptr;
        
        int rootIndex = mp[preorder[preLeft]];

        TreeNode* root = new TreeNode(preorder[preLeft]);
        root->left = dfs(preorder, inorder, preLeft + 1, rootIndex - inLeft + preLeft, inLeft, rootIndex - 1);
        root->right = dfs(preorder, inorder, rootIndex - inLeft + preLeft + 1, preRight, rootIndex + 1, inRight);
        
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++)
            mp[inorder[i]] = i;

        return dfs(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }
};