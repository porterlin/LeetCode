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
    TreeNode* replaceValueInTree(TreeNode* root) {
        unordered_map<TreeNode*, pair<TreeNode*, int>> sibling;
        sibling[root] = {nullptr, 0};
        deque<TreeNode*> dq;
        dq.push_back(root);
        while (!dq.empty()) {
            int sumDq = 0;
            for (auto buf : dq)
                sumDq += buf->val;
            
            cout << sumDq << endl;
            int n = dq.size();
            for (int i = 0; i < n; i++) {
                TreeNode* node = dq.front();
                dq.pop_front();
                if (node->left && node->right) {
                    dq.push_back(node->left);
                    dq.push_back(node->right);
                    sibling[node->left] = {node->right, node->right->val};
                    sibling[node->right] = {node->left, node->left->val};
                } else if (node->left) {
                    dq.push_back(node->left);
                    sibling[node->left] = {nullptr, 0};
                } else if (node->right) {
                    dq.push_back(node->right);
                    sibling[node->right] = {nullptr, 0};
                }

                if (sibling[node].first != nullptr) {
                    if (node->val + sibling[node].second == sumDq)
                        node->val = 0;
                    else
                        node->val = sumDq - sibling[node].second - node->val;
                } else {
                    node->val = sumDq - node->val;
                }
            }
        }
        return root;
    }
};