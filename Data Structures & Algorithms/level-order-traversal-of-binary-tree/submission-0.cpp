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
    void insertLevel(TreeNode* r, int level, vector<vector<int>>& output) {
        if (!r) return;
        if (output.size() <= level) output.push_back({});
        output[level].push_back(r->val);
        insertLevel(r->left, level+1, output);
        insertLevel(r->right, level+1, output);
    }
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> output;
        insertLevel(root, 0, output);
        return output;
    }
};
