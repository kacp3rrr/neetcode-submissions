# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def goodNodes(self, root: TreeNode) -> int:
        count = 0
        def dfs(root: TreeNode, maximum: int) -> None:
            nonlocal count
            if not root:
                return
            if root.val >= maximum:
                count += 1
                maximum = root.val
            dfs(root.left, maximum)
            dfs(root.right, maximum)
        dfs(root, root.val)
        return count