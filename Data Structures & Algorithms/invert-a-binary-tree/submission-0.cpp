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
private:
    void helper(TreeNode* r) {
        if (r == nullptr || (r->left == nullptr && r->right == nullptr)) {
            return;
        } 
        TreeNode* temp = r->left;
        r->left = r->right;
        r->right = temp;
        helper(r->left);
        helper(r->right);
    }
public:
    TreeNode* invertTree(TreeNode* root) {
        helper(root);
        return root;
    }
};
