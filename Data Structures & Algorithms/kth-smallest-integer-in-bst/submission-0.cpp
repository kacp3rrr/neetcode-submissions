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
    int ct = 0;
    int k;
    int res;
    void trav(TreeNode* r) {
        if (!r) return; 
        trav(r->left);
        ++ct;
        if (ct == k) {
            res = r->val;
            return;
        }
        trav(r->right);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        this->k = k;
        trav(root);
        return res;
    }
};
