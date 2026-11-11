# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def lowestCommonAncestor(self, root: TreeNode, p: TreeNode, q: TreeNode) -> TreeNode:
        left = p if p.val <= q.val else q
        right = p if p.val > q.val else q
        lca = root
        def traverse(node: TreeNode):
            nonlocal lca

            if not node:
                return

            # where the current node partitions the two elements, whereby it is the lowest common
            # ancestor
            if left.val <= node.val <= right.val:
                lca = node
                return
            else:
                traverse(node.left)
                traverse(node.right)
        
        traverse(root)
        return lca