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
    vector<vector<int>> res;
    void traverse(TreeNode* r, int level) {
        if (!r) return;
        if (res.size() <= level) res.push_back({});
        res[level].push_back(r->val);
        traverse(r->left, level+1);
        traverse(r->right, level+1);
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        // do a level order traversal, then for each level, return the last element
        traverse(root, 0);
        vector<int> output;
        for (const vector<int>& v : res) {
            output.push_back(v[v.size() - 1]);
        }
        return output;
    }
};
