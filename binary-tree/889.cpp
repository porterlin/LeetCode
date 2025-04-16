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
    TreeNode* dfs(vector<int>& preorder, vector<int>& postorder, int preLeft, int preRight, int postLeft, int postRight) {
        if (preLeft > preRight)
            return nullptr;

        TreeNode* root = new TreeNode(preorder[preLeft]);
        if (preLeft == preRight)
            return root;

        int rootIndex = mp[preorder[preLeft + 1]];

        root->left = dfs(preorder, postorder, preLeft + 1, preLeft + rootIndex - postLeft + 1, postLeft, rootIndex);
        root->right = dfs(preorder, postorder, preLeft + rootIndex - postLeft + 2, preRight, rootIndex + 1, postRight - 1);

        return root;
    }

    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        for (int i = 0; i < postorder.size(); i++)
            mp[postorder[i]] = i;
        return dfs(preorder, postorder, 0, preorder.size() - 1, 0, postorder.size() - 1);
    }
};